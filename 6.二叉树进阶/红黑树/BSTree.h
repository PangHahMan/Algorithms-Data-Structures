#pragma once
#include<utility>
using namespace std;

//红黑树节点颜色
enum Colour
{
	RED,
	BLACK,
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K,V>* _left;
	RBTreeNode<K,V>* _right;
	RBTreeNode<K,V>* _parent;
	pair<K,V> _kv;
	Colour _col;

	RBTreeNode(const pair<K,V>& kv)
	:_left(nullptr)
	,_right(nullptr)
	,_parent(nullptr)
	,_kv(kv)
	,_col(RED)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K,V> Node;
public:
	bool Insert(const pair<K, V> &kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
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

		while(parent && parent->_col==RED)
		{
			Node* grandfather = parent->_parent;
			//如果爷爷的左边是父亲，那么爷爷的右边就是叔叔
			if(grandfather->_left==parent)
			{
				Node* uncle = grandfather->_right;
				if(uncle && uncle == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续网上调整
					//重置parent，先将grandfather位置看成新增结点cur
					cur = grandfather;
					parent = cur->_parent;
				}
			}
		}
		//最后的根变为黑节点
		_root->_col = BLACK;
		return true;
	}
private:
	Node* _root;
};