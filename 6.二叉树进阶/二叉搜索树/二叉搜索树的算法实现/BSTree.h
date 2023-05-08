#pragma once
#include <iostream>
using namespace std;

template <class K>
// 二叉树的结构
struct BSTreeNode
{
    BSTreeNode<K>* _left;
    BSTreeNode<K>* _right;
    K _key;

    BSTreeNode(const K& key)
        : _left(nullptr), _right(nullptr), _key(key)
    {
    }
};

template <class K>
class BSTree
{
    typedef BSTreeNode<K> Node;

public:
    BSTree() = default;  //指定强制生成默认构造
   
    BSTree(const BSTree<K>& t)
    {
        _root = Copy(t._root);
    }

    BSTree<K>& operator=(BSTree<K> t)
    {
        swap(_root, t._root);
        return *this;
    }

    ~BSTree()
    {
        Destroy(_root);
    }

    bool Insert(const K& key)
    {
        // 如果根一开始就为nullptr，那么就直接构建初始的根
        if (_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }

        // 如果_root不为nullptr，那么就从根开始遍历，找适合的位置
        Node* parent = nullptr; // parent跟着cur遍历找到合适的位置，充当插入的父亲节点
        Node* cur = _root;
        while (cur)
        {
            if (key < cur->_key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (key > cur->_key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else // 如果key == cur->_key  那么就直接返回false，二叉搜索树的值不允许相同
            {
                return false;
            }
        }
        // 找到后就开始链接
        cur = new Node(key);
        // 这里不知道cur最终走到了parent的左边还是右边，所以还要进行判断
        if (key > parent->_key)
        {
            parent->_right = cur;
        }
        else if (key < parent->_key)
        {
            parent->_left = cur;
        }
        return true;
    }

    // 查找
    bool Find(const K& key)
    {
        Node* cur = _root;
        while (cur)
        {
            if (key > cur->_key)
            {
                cur = cur->_right;
            }
            else if (key < cur->_key)
            {
                cur = cur->_left;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    // 删除
    bool Erase(const K& key)
    {
        Node* parent = nullptr;
        Node* cur = _root;
        while (cur != nullptr)
        {
            if (key > cur->_key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (key < cur->_key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                // 开始删除
                // 1.如果要删除的cur左边是nullptr，那么我们就进行判断，判断cur在parent的左子树还是右子树，
                // 如果是左子树，那么就由parent的left指向cur的右子树，如果是右子树，就由parent的right指向cur的右子树
                if (cur->_left == nullptr)
                {
                    // if (parent == nullptr)
                    if (cur == _root)
                    {
                        _root = cur->_right;
                    }
                    else
                    {
                        if (parent->_left == cur)
                        {
                            parent->_left = cur->_right;
                        }
                        else
                        {
                            parent->_right = cur->_right;
                        }
                    }

                    delete cur;
                } // 2.cur的右边为nullptr
                else if (cur->_right == nullptr)
                {
                    // if (parent == nullptr)
                    if (cur == _root)
                    {
                        _root = cur->_left;
                    }
                    else
                    {
                        if (parent->_left == cur)
                        {
                            parent->_left = cur->_left;
                        }
                        else
                        {
                            parent->_right = cur->_left;
                        }
                    }

                    delete cur;
                }
                else // 都不为nullptr,替代法，用被删除的cur的左子树的最大节点，右子树的最大节点替换
                {
                    // 找cur右子树的最大节点
                    Node* pminRight = cur;
                    Node* minRight = cur->_right;
                    // 找右子树，右子树的最小位置在右子树的左边
                    while (minRight->_left)
                    {
                        pminRight = minRight;
                        minRight = minRight->_left;
                    }
                    // 找到最小的值赋值给cur
                    cur->_key = minRight->_key;

                    // pminRight->_left==minRight 那么左边已经是最小了，所以minRight的左子树肯定为空了
                    // 那么可能minRight还有右子树，所以需要pinRight来领养
                    if (pminRight->_left == minRight)
                    {
                        pminRight->_left = minRight->_right;
                    }
                    else // 如果不是，比如删除根节点，那么就需要将pminRight->_right指向minRight->right(最小值左边一定为NULL。不需要领养)
                    {
                        pminRight->_right = minRight->_right;
                    }

                    delete minRight;
                }
                return true;
            }
        }
        return false;
    }

    bool _FindR(Node* root,const K& key)
    {
        if (root == nullptr)
            return false;

        if (root->_key == key)
            return true;

        if (key > root->_key)
            return _FindR(root->_right, key);
        else
            return _FindR(root->_left, key);
    }

    Node* Copy(Node* root)
    {
        if (root == nullptr)
            return nullptr;
        Node* newRoot = new Node(root->_key);
        newRoot->_left = Copy(root->_left);
        newRoot->_right = Copy(root->_right);
        
        return newRoot;
    }

    void Destroy(Node*& root)
    {
        if (root == nullptr)
            return;
        Destroy(root->_left);
        Destroy(root->_right);

        delete root;
        root = nullptr;
    }

    bool FindR(const K& key)
    {
        return _FindR(_root, key);
    }

    bool _InsertR(Node*& root, const K& key)
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return root;
        }

        if (key > root->_key)
        {
            return _InsertR(root->_right, key);
        }
        else if (key < root->_key)
        {
            return _InsertR(root->_left, key);
        }
        else
        {
            return false;
        }
    }

    bool InsertR(const K& key)
    {
        return _InsertR(_root, key);
    }

    bool _EraseR(Node*& root, const K& key)
    {
        if (root == nullptr)
            return false;

        if (key > root->_key)
        {
            return _EraseR(root->_right, key);
        }
        else if (key < root->_key)
        {
            return _EraseR(root->_left, key);
        }
        else
        {
            Node* del = root;
            //开始准备删除，root谁上层root->_left/_right的引用
            if (root->_right == nullptr)
            {
                //上层的左右指向当前层的左右
                root = root->_left;
            }
            else if (root->_left == nullptr)
            {
                root = root->_right;
            }
            else
            {
                Node* maxleft = root->_left;
                //找最大，最大在右边
                while (maxleft->_right)
                {
                    maxleft = maxleft->_right;
                }

                swap(root->_key,maxleft->_key);

                //转换在子树去删除
                //这里不能传maxleft，maxleft是局部变量
                return _EraseR(root->_left, key);
            }
            delete del;
            return true;
        }
    }

    bool EraseR(const K& key)
    {
        return _EraseR(_root, key);
    }
    // 一般调用为t.InOrder()  不传参数，所以这里进行了封装
    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }
protected:
    void _InOrder(Node* root)
    {
        if (root == nullptr)
            return;

        _InOrder(root->_left);
        cout << root->_key << " ";
        _InOrder(root->_right);
    }

private:
    Node* _root = nullptr; // 二叉搜索树的根
};