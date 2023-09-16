#pragma once
#include <assert.h>
#include <iostream>
#include <utility>
using namespace std;

// AVL平衡树，左右高度差不超过1
template<class K, class V>
struct AVLTreeNode {
    AVLTreeNode<K, V> *_left;
    AVLTreeNode<K, V> *_right;
    AVLTreeNode<K, V> *_parent;
    pair<K, V> _kv;// 存储键值对的pair对象；pair是一个模板类，它可以用来存储两个不同类型的值,头文件utility

    int _bf;// balance factor 平衡因子，用于AVL树的平衡操作。 -1 0 1是正常的平衡因子

    AVLTreeNode(const pair<K, V> &kv)// 构造函数传参为一个pair对象
        : _left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv), _bf(0) {
    }
};

template<class K, class V>
class AVLTree {
public:
    typedef AVLTreeNode<K, V> Node;
    bool Insert(const pair<K, V> &kv) {
        //空树就new一个
        if (_root == nullptr) {
            _root = new Node(kv);
            return true;
        }

        //先查找
        Node *parent = nullptr;
        Node *cur = _root;
        while (cur) {
            if (kv.first > cur->_kv.first) {
                parent = cur;
                cur = cur->_right;
            } else if (kv.first < cur->_kv.first) {
                parent = cur;
                cur = cur->_left;
            } else {
                // 相等则不插入,
                return false;
            }
        }
        // cur走到了合适的位置
        cur = new Node(kv);
        // 选择插入到parent的左边还是右边
        if (kv.first < parent->_kv.first) {
            parent->_left = cur;
        } else {
            parent->_right = cur;
        }
        // cur链接parent
        cur->_parent = parent;

        // 更新平衡因子
        // 1.如果更新完以后，平衡因子没有出现问题(|bf|<=1)，不需要处理
        // 2.如果更新完以后，平衡出现问题(|bf|>1)，需要处理(旋转)

        // 插入新增节点。会影响祖先的平衡因子(全部或者部分)
        // 1、cur == parent->right  parent->bf++
        // 2、cur == parent->left   parent->bf--

        // 什么决定了是否继续往上更新祖先节点，取决于parent所在的子树高度是否变化？变了继续更新，不变则不再更新
        // a、parent->bf==1 || parent->bf == -1   parent所在的子树变了，需要继续更新祖先节点
        // b、parent->bf==2 || parent->bf == -1   parent所在的子树不平衡，需要处理这颗子树(旋转)
        // c、parent->bf==0, parent所在的子树高度不变，不用继续网上更新。插入结束 为什么?
        //  说明插入前parent->bf==1 or -1，插入之前一边高，一边低。插入节点插入矮的那边，它的高度不变

        while (parent) {
            //插入后,判断孩子插入到左边还是右边 进行++ --平衡因子
            if (cur == parent->_right) {
                parent->_bf++;
            } else {
                parent->_bf--;
            }

            if (parent->_bf == 1 || parent->_bf == -1) {
                // 更新祖先节点的bf
                parent = parent->_parent;
                cur = cur->_parent;
            } else if (parent->_bf == 0) {
                // 平衡，不需要处理
                break;
            } else if (parent->_bf == 2 || parent->_bf == -2) {
                // 需要旋转处理
                // 当parent->bf == 2 && cur->bf == 1 右边高，需要左单旋
                // 当parent->_bf == -2 && cur->_bf == -1 左边高，需要右单旋
                // 当parent->_bf == -2 && cur->_bf == 1 需要左右双旋转
                // 当parent->_bf == 2 && cur->_bf == -1 需要右左双旋转
                if (parent->_bf == 2 && cur->_bf == 1) {
                    RotateLeft(parent);
                } else if (parent->_bf == -2 && cur->_bf == -1) {
                    RotateRight(parent);
                } else if (parent->_bf == -2 && cur->_bf == 1) {
                    RotateLR(parent);
                } else if (parent->_bf == 2 && cur->_bf == -1) {
                    RotateRL(parent);
                }

                break;
            }
        }
        return true;
    }

    void InOrder() {
        _InOrder(this->_root);
        cout << endl;
    }

    bool IsBalanace() {
        return _IsBalanace(this->_root);
    }

    int Height() {
        return _Height(this->_root);
    }

    int _Height(Node *root) {
        if (root == nullptr)
            return 0;

        int leftHeight = _Height(root->_left) + 1;
        int rightHeight = _Height(root->_right) + 1;

        return leftHeight > rightHeight ? leftHeight : rightHeight;
    }

    // 判断是否是平衡树
    bool _IsBalanace(Node *root) {
        if (root == nullptr) {
            return true;
        }

        int leftHeight = _Height(root->_left);
        int rightHeight = _Height(root->_right);

        if (rightHeight - leftHeight != root->_bf) {
            cout << root->_kv.first << "节点平衡因子异常" << endl;
            return false;
        }

        return abs(leftHeight - rightHeight) < 2 && _IsBalanace(root->_left) && _IsBalanace(root->_right);
    }

    bool Modify(const K &key, const V &value) {
        Node *ret = Find(key);
        //没找到key则返回false
        if (ret == nullptr) {
            return false;
        }

        ret->_kv.second = value;
        return true;
    }

    bool Erase(const K &key) {
        //遍历二叉树
        Node *parent = nullptr;
        Node *cur = _root;
        //用于标记实际的删除结点及其父结点
        Node *delParentPos = nullptr;
        Node *delPos = nullptr;
        //找key值
        while (cur) {
            if (key < cur->_kv.first) {
                parent = cur;
                cur = cur->_left;
            } else if (key > cur->_kv.first) {
                parent = cur;
                cur = cur->_right;
            } else {//找到待删除结点
                //待删除结点的左子树为空
                if (cur->_left == nullptr) {
                    //待删除结点是根结点，让根结点的右子树作为新的根结点
                    if (cur == _root) {
                        _root = _root->_right;
                        if (_root) {
                            _root->_parent = nullptr;
                        }
                        delete cur;
                    } else {
                        //带删除结点不是根结点
                        delParentPos = parent;//标记实际删除结点的父结点
                        delPos = cur;         //标记实际删除的结点
                    }
                    break;                          ////跳出循环,之后更新平衡因子
                } else if (cur->_right == nullptr) {//待删除结点的右子树为空
                    //待删除结点是根结点,让根结点的左子树作为新的根结点
                    if (cur == _root) {
                        _root = _root->_left;
                        if (_root) {
                            _root->_parent = nullptr;
                        }
                        delete cur;
                        return true;
                    } else {
                        //带删除结点不是根结点
                        delParentPos = parent;
                        delPos = cur;
                    }
                    break;//跳出循环,之后更新平衡因子
                } else {  //待删除结点左右两边都不为空
                    //使用替换法进行删除
                    //找右子树中的最小结点成为待删除结点作为子树的根
                    Node *minParent = cur;
                    Node *minRight = cur->_right;
                    //最小结点在最左边
                    while (minRight->_left) {
                        minParent = minRight;
                        minRight = minRight->_left;
                    }

                    //更新待删除结点
                    cur->_kv.first = minRight->_kv.first;
                    cur->_kv.second = minRight->_kv.second;
                    //更新待删除的结点，此时待删除的结点就是minRight
                    delParentPos = minParent;
                    delPos = minRight;
                    //跳出循环,更新平衡因子
                    break;
                }
            }
        }

        //key值不对，走到了nullptr,还没有找到key，说明要找的key不存在,返回false
        if (delPos == nullptr) {
            //删除结点没有修改过,则返回false
            return false;
        }

        //记录待删除结点及其父结点（用于后续实际删除）
        Node *del = delPos;
        Node *delParent = delParentPos;

        //更新平衡因子
        //待删除的结点不是根
        while (delPos != _root) {
            //删除结点在父结点左边需要++，在右边需要--
            if (delPos == delParentPos->_left) {
                delParentPos->_bf++;
            } else if (delPos == delParent->_right) {
                delParentPos->_bf--;
            }

            //判断是否更新结束或需要进行旋转
            //_bf == 0 需要向上更新
            //_bf == -1/1 不需要更新
            //_bf == -2/2 需要旋转
            if (delParentPos->_bf == 0) {
                //delParentPos树的高度变化，会影响其父结点的平衡因子，需要继续往上更新平衡因子
                delPos = delParentPos;
                delParentPos = delParentPos->_parent;
            } else if (delParentPos->_bf == -1 || delParentPos->_bf == 1) {
                //delParent树的高度没有发生变化，不会影响其父结点及以上结点的平衡因子
                break;
            } else if (delParentPos->_bf == -2 || delParentPos->_bf == 2) {
                //6种旋转
                if (delParentPos->_bf == -2) {
                    if (delParentPos->_left->_bf == -1) {
                        Node *tmp = delParentPos->_left;//记录delParentPos右旋转后新的根结点
                        RotateRight(delParentPos);      //右单旋
                        delParentPos = tmp;             //更新根结点
                    } else if (delParentPos->_left->_bf == 1) {
                        Node *tmp = delParentPos->_left->_right;//记录delParentPos左右双旋后新的根结点
                        RotateLR(delParentPos);                 //左右双旋
                        delParentPos = tmp;
                    } else {
                        Node *tmp = delParentPos->_left;
                        RotateRight(delParentPos);//右单旋
                        delParentPos = tmp;       //更新根结点

                        //平衡因子调整
                        delParentPos->_bf = 1;
                        delParentPos->_right->_bf = -1;
                        break;
                    }
                } else if (delParentPos->_bf == 2) {
                    if (delParentPos->_right->_bf = -1) {
                        Node *tmp = delParentPos->_right->_left;//记录delParentPos右左旋转后新的根结点
                        RotateRL(delParentPos);                 //右左双旋
                        delParentPos = tmp;
                    } else if (delParentPos->_right->_bf == 1) {
                        Node *tmp = delParentPos->_right;//记录delParentPos左旋转后新的根结点
                        RotateLeft(delParentPos);        //左旋转
                        delParentPos = tmp;
                    } else {//bf==0
                        Node *tmp = delParentPos->_right;
                        RotateLeft(delParentPos);
                        delParentPos = tmp;

                        //更新平衡因子
                        delParentPos->_bf = -1;
                        delParentPos->_bf = 1;
                        break;
                    }
                }
                //旋转后delParentPos树的高度变化，会影响其父结点的平衡因子，需要继续往上更新平衡因子
                delPos = delParentPos;
                delParentPos = delParentPos->_parent;
            } else {
                //在删除前树的平衡因子就有问题
                assert(false);
            }
        }

        //进行实际删除
        if (del->_left == nullptr) {      //实际删除结点的左子树为空
            if (del == delParent->_left) {//实际删除结点是其父结点的左孩子
                //让父亲的左孩子指向被删除结点的有孩子
                delParent->_left = del->_right;
                //如果有孩子不为空,绑定右孩子的父亲
                if (del->_right) {
                    del->_right->_parent = delParent;
                }
            } else {//实际删除结点是其父结点的右孩子
                //直接领养被删除结点的右孩子,右孩子不为空则绑定父亲
                delParent->_right = del->_right;
                if (del->_right) {
                    del->_right->_parent = delParent;
                }
            }
        } else {//实际删除结点的右子树为
            //实际删除结点是其父结点的左孩子
            if (del == delParent->_left) {
                //被删除结点父亲领养被删除结点的左孩子
                delParent->_left = del->_left;
                //绑定父亲
                if (del->_left) {
                    del->_left->_parent = delParent;
                }

            } else {//实际删除结点是其父结点的右孩子
                //领养被删除结点左孩子,并绑定父亲
                delParent->_right = del->_left;
                if (del->_left) {
                    del->_left->_parent = delParent;
                }
            }
        }
        delete del;

        return true;
    }

private:
    void _InOrder(Node *root) {
        if (root == nullptr) {
            return;
        }
        _InOrder(root->_left);
        cout << root->_kv.first << " ";
        _InOrder(root->_right);
    }

    // 左单旋
    void RotateLeft(Node *parent) {
        Node *subR = parent->_right;// 要旋转的parent的右子树
        Node *subRL = subR->_left;  // 子树的左子树

        // 旋转链接
        parent->_right = subRL;
        // subRL不为nullptr
        if (subRL) {
            subRL->_parent = parent;
        }

        // 需要记录要旋转的树还有没有父亲
        Node *ppnode = parent->_parent;

        subR->_left = parent;
        parent->_parent = subR;

        // 如果ppnode为nullptr，说明parent一开始为根，旋转后subR为根
        if (ppnode == nullptr) {
            // 更新根节点
            _root = subR;
            _root->_parent = nullptr;
        } else {
            if (ppnode->_left == parent) {
                ppnode->_left = subR;
            } else {
                ppnode->_right = subR;
            }
            subR->_parent = ppnode;
        }
        // 更新平衡因子
        parent->_bf = subR->_bf = 0;
    }

    // 右单旋
    void RotateRight(Node *parent) {
        Node *subL = parent->_left;//parent的左数
        Node *subLR = subL->_right;//subL的右树

        parent->_left = subLR;//将subLR的右数作为parent的左数
        if (subLR) {
            subLR->_parent = parent;//更新subLR的父亲
        }

        Node *ppnode = parent->_parent;//记录祖先结点

        subL->_right = parent; //subL的右数更新为parent
        parent->_parent = subL;//更新parent的父亲

        //祖先结点链接更新后的父亲(subL)
        if (ppnode == nullptr) {
            _root = subL;
            _root->_parent = nullptr;
        } else {
            if (ppnode->_left == parent) {
                ppnode->_left = subL;
            } else {
                ppnode->_right = subL;
            }
            subL->_parent = ppnode;
        }
        //更新平衡因子
        parent->_bf = subL->_bf = 0;
    }

    // 双旋(左右旋转)
    void RotateLR(Node *parent) {
        Node *subL = parent->_left;
        Node *subLR = subL->_right;
        // subLR的平衡因子决定了，在哪里插入
        int bf = subLR->_bf;

        RotateLeft(parent->_left);
        RotateRight(parent);

        //更新平衡因子
        if (bf == 1) {
            parent->_bf = 0;
            subLR->_bf = 0;
            subL->_bf = -1;
        } else if (bf == -1) {
            parent->_bf = 1;
            subLR->_bf = 0;
            subL->_bf = 0;
        } else if (bf == 0) {
            parent->_bf = 0;
            subLR->_bf = 0;
            subL->_bf = 0;
        } else {
            assert(false);
        }
    }

    // 双旋(右左旋转)
    void RotateRL(Node *parent) {
        Node *subR = parent->_right;
        Node *subRL = subR->_left;

        int bf = subRL->_bf;
        //右单旋从parent->right开始旋转
        RotateRight(parent->_right);
        RotateLeft(parent);

        //更新平衡因子
        if (bf == 1) {
            parent->_bf = -1;
            subRL->_bf = 0;
            subR->_bf = 0;
        } else if (bf == -1) {
            parent->_bf = 0;
            subRL->_bf = 0;
            subR->_bf = 1;
        } else if (bf == 0) {
            parent->_bf = 0;
            subRL->_bf = 0;
            subR->_bf = 0;
        } else {
            assert(false);
        }
    }

    Node *Find(const K &key) {
        Node *cur = _root;
        while (cur) {
            //key值小于该结点的值
            if (key < cur->_kv.first) {
                //在该结点的左子树当中查找
                cur = cur->_left;
            } else if (key > cur->_kv.first) {
                //key值大于该结点的值
                cur = cur->_right;//在该结点的右子树当中查找
            } else {
                //找到了目标结点
                return cur;//返回该结点
            }
        }
        return nullptr;
    }


private:
    Node *_root = nullptr;
};
