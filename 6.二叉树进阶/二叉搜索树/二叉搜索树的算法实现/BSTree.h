#pragma once
#include <iostream>
using namespace std;

template <class K>
// �������Ľṹ
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
    BSTree() = default;  //ָ��ǿ������Ĭ�Ϲ���
   
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
        // �����һ��ʼ��Ϊnullptr����ô��ֱ�ӹ�����ʼ�ĸ�
        if (_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }

        // ���_root��Ϊnullptr����ô�ʹӸ���ʼ���������ʺϵ�λ��
        Node* parent = nullptr; // parent����cur�����ҵ����ʵ�λ�ã��䵱����ĸ��׽ڵ�
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
            else // ���key == cur->_key  ��ô��ֱ�ӷ���false��������������ֵ��������ͬ
            {
                return false;
            }
        }
        // �ҵ���Ϳ�ʼ����
        cur = new Node(key);
        // ���ﲻ֪��cur�����ߵ���parent����߻����ұߣ����Ի�Ҫ�����ж�
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

    // ����
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

    // ɾ��
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
                // ��ʼɾ��
                // 1.���Ҫɾ����cur�����nullptr����ô���Ǿͽ����жϣ��ж�cur��parent��������������������
                // ���������������ô����parent��leftָ��cur���������������������������parent��rightָ��cur��������
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
                } // 2.cur���ұ�Ϊnullptr
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
                else // ����Ϊnullptr,��������ñ�ɾ����cur�������������ڵ㣬�����������ڵ��滻
                {
                    // ��cur�����������ڵ�
                    Node* pminRight = cur;
                    Node* minRight = cur->_right;
                    // ��������������������Сλ���������������
                    while (minRight->_left)
                    {
                        pminRight = minRight;
                        minRight = minRight->_left;
                    }
                    // �ҵ���С��ֵ��ֵ��cur
                    cur->_key = minRight->_key;

                    // pminRight->_left==minRight ��ô����Ѿ�����С�ˣ�����minRight���������϶�Ϊ����
                    // ��ô����minRight������������������ҪpinRight������
                    if (pminRight->_left == minRight)
                    {
                        pminRight->_left = minRight->_right;
                    }
                    else // ������ǣ�����ɾ�����ڵ㣬��ô����Ҫ��pminRight->_rightָ��minRight->right(��Сֵ���һ��ΪNULL������Ҫ����)
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
            //��ʼ׼��ɾ����root˭�ϲ�root->_left/_right������
            if (root->_right == nullptr)
            {
                //�ϲ������ָ��ǰ�������
                root = root->_left;
            }
            else if (root->_left == nullptr)
            {
                root = root->_right;
            }
            else
            {
                Node* maxleft = root->_left;
                //�����������ұ�
                while (maxleft->_right)
                {
                    maxleft = maxleft->_right;
                }

                swap(root->_key,maxleft->_key);

                //ת��������ȥɾ��
                //���ﲻ�ܴ�maxleft��maxleft�Ǿֲ�����
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
    // һ�����Ϊt.InOrder()  ����������������������˷�װ
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
    Node* _root = nullptr; // �����������ĸ�
};