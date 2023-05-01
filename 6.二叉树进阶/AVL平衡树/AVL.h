#pragma once
#include <utility>
#include <cassert>
using namespace std;

// AVL平衡树，左右高度差不超过1
template <class K, class V>
class AVLTreeNode
{
    AVLTreeNode<K, V> *_left;
    AVLTreeNode<K, V> *_right;
    AVLTreeNode<K, V> *_parent;
    pair<K, V> _kv; // 存储键值对的pair对象；pair是一个模板类，它可以用来存储两个不同类型的值,头文件utility

    int _bf; // balance factor 平衡因子，用于AVL树的平衡操作。 -1 0 1是正常的平衡因子

    AVLTreeNode(const pair<K, V> &kv) // 构造函数传参为一个pair对象
        : _left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv), _bf(0)
    {
    }
};

template <class K, class V>
class AVLTree
{
    typedef AVLTreeNode<K, V> Node;

public:
    bool Insert(const pair<K, V> &kv)
    {
        if (_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }

        Node *parent = nullptr;
        Node *cur = _root;
        while (cur)
        {
            if (kv.first > cur->_kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (kv.first < cur->_kv.first)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                // 相等则不插入
                return false;
            }
        }
        // cur走到了合适的位置
        cur = new Node(kv);
        // 选择插入到parent的左边还是右边
        if (kv.first < parent->_kv.first)
        {
            parent->_left = cur;
        }
        else
        {
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
        // a、parent->bf==1 || parent->bf == -1   parent所在的字数变了，需要继续更新祖先节点
        // b、parent->bf==2 || parent->bf == -1   parent所在的字数不平衡，需要处理这颗子树(旋转)
        // c、parent->bf==0, parnet所在的子树高度不变，不用继续网上更新。插入结束 为什么?
        //  说明插入前parent->bf==1 or -1，插入之前一边高，一边低。插入节点插入矮的那边，它的高度不变

        while (parent)
        {
            if (cur = parent->_right)
            {
                parent->_bf++;
            }
            else
            {
                parent->_bf--;
            }

            if (parent->_bf == 1 || parent->_bf == -1)
            {
                // 更新祖先节点的bf
                parent = parent->_parent;
                cur = cur->_parent;
            }
            else if (parent->bf == 2 || parent->_bf == -2)
            {
                // 需要旋转处理
            }
            else if (parent->_bf == 0)
            {
                // 平衡，不需要处理
                break;
            }
            else
            {
                assert(false);
            }
        }
        return true;
    }

private:
    Node *_root = nullptr;
};