#pragma once
#include <utility>
#include <assert.h>
using namespace std;

// AVL平衡树，左右高度差不超过1
template <class K, class V>
struct AVLTreeNode
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
public:
	typedef AVLTreeNode<K, V> Node;
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
		// c、parent->bf==0, parent所在的子树高度不变，不用继续网上更新。插入结束 为什么?
		//  说明插入前parent->bf==1 or -1，插入之前一边高，一边低。插入节点插入矮的那边，它的高度不变

		while (parent)
		{
			if (cur == parent->_right)
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
			else if (parent->_bf == 0)
			{
				// 平衡，不需要处理
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 需要旋转处理
				// 当parent->bf == 2 && cur->bf == 1 右边高，需要左单旋
				// 当parent->_bf == -2 && cur->_bf == -1 左边高，需要右单旋
				// 当parent->_bf == -2 && cur->_bf == 1 左边高，
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateLeft(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateRight(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}

				break;
			}
		}
		return true;
	}

	void InOrder()
	{
		_InOrder(this->_root);
		cout << endl;
	}

	bool IsBalanace()
	{
		return _IsBalanace(this->_root);
	}

	int Height()
	{
		return _Height(this->_root);
	}

private:
	int _Height(Node *root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = _Height(root->_left) + 1;
		int rightHeight = _Height(root->_right) + 1;

		return leftHeight > rightHeight ? leftHeight : rightHeight;
	}
	// 判断是否是平衡树
	bool _IsBalanace(Node *root)
	{
		if (root == nullptr)
			return true;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		if (rightHeight - leftHeight != root->_bf)
		{
			cout << root->_kv.first << "节点平衡因子异常" << endl;
			return false;
		}

		return abs(leftHeight - rightHeight) < 2 && _IsBalanace(root->_left) && _IsBalanace(root->_right);
	}

	void _InOrder(Node *root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	// 左单旋
	void RotateLeft(Node *parent)
	{
		Node *subR = parent->_right; // 要旋转的parent的右子树
		Node *subRL = subR->_left;	 // 子树的左子树

		// 旋转链接
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		// 需要记录要旋转的树还有没有父亲
		Node *ppnode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		// 如果ppnode为nullptr，说明parent一开始为根，旋转后subR为根
		if (ppnode == nullptr)
		{
			// 更新根节点
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}
		// 更新平衡因子
		parent->_bf = subR->_bf = 0;
	}

	// 右单旋
	void RotateRight(Node *parent)
	{
		Node *subL = parent->_left;
		Node *subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node *ppnode = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (ppnode == nullptr)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}
			subL->_parent = ppnode;
		}
		parent->_bf = subL->_bf = 0;
	}

	// 双旋(左右旋转)
	void RotateLR(Node *parent)
	{
		Node *subL = parent->_left;
		Node *subLR = subL->_right;
		// subLR的平衡因子决定了，在哪里插入
		int bf = subLR->_bf;

		RotateLeft(parent->_left);
		RotateRight(parent);

		if (bf == 1)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	// 双旋(右左旋转)
	void RotateRL(Node *parent)
	{
		Node *subR = parent->_right;
		Node *subRL = subR->_left;

		int bf = subRL->_bf;

		RotateRight(parent->_right);
		RotateLeft(parent);

		if (bf == 1)
		{
			parent->_bf = -1;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

private:
	Node *_root = nullptr;
};
