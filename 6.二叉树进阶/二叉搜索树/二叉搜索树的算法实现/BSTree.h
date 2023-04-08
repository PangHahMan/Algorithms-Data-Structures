#pragma once

//class BinarySearchTree
template<class K>
struct BSTreeNode
{
	BSTreeNode()
		:_left(nullptr)
		,_right(nullptr)
	{}

	BSTreeNode(K key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(K key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		//���Ӹ��׽��
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

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

	//�ѵ�
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(key<cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//ɾ��
				//1.��Ϊ��
				if (cur->_left == nullptr)
				{
					//���Ҫɾ���Ľ����parent����ڵ㣬��ô������parent��left����֮
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
					delete cur;
				}//2.��Ϊ��
				else if (cur->_right == nullptr)
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
					delete cur;
				}//3.�뱣ķ
				else
				{
					//����������С��������Ҳ��������������������
					Node* pminRight = nullptr;   //��С���ĸ��׽��
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						pminRight = minRight;
						minRight = minRight->_left;
					}
					cur->_key = minRight->_key;
					if (pminRight)
					{
						pminRight->_left = cur->_right;
					}
				}

				return true;
			}
		}
		return false;
	}

	void InOrder()
	{
		_InOrder(_root);
	}
	//�������
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:	
	Node* _root = nullptr;
};