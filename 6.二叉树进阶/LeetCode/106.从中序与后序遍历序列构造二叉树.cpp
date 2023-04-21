struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
后序遍历的最后一个元素一定是根节点。我们可以根据这个元素找到中序遍历中根节点的位置，然后确定左右子树的范围。
由于中序遍历是左根右的顺序，所以根节点的左边就是左子树的中序遍历，根节点的右边就是右子树的中序遍历。
由于后序遍历是左右根的顺序，所以从后序遍历的最后一个元素开始，往左数根节点的位置就是左子树的后序遍历，往右数根节点的位置就是右子树的后序遍历。
然后我们就可以递归的构造左右子树了。
*/

#include <vector>
using namespace std;
class Solution
{
public:
    TreeNode *_bulid(vector<int> &inorder, vector<int> &postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right)
    {
        // 递归条件
        if (inorder_left > inorder_right)
        {
            return nullptr;
        }
        // 后序遍历的最后一个一定是根节点
        int postorder_root = postorder_right;
        int inorder_root = inorder_left;
        // 通过后序遍历找到的根节点的值，找inorder里根节点的位置
        while (inorder[inorder_root] != postorder[postorder_root])
        {
            inorder_root++;
        }
        // 定义左子树的节点个数,用于确认后序遍历划分区间，后序遍历划分区间也是根据中序遍历的根来确定的，中序遍历根的左子树，就是后序遍历的左子树
        int left_subtree_size = inorder_root - inorder_left;
        TreeNode *root = new TreeNode(postorder[postorder_root]);
        // 递归左子树，中序遍历划分区间，后序遍历划分区间
        // 中序遍历区间[inorder_left,inorder_root -1]  inorder_root   [inorder_root+1,inorder_right]
        // 后序遍历区间[postorder_left,postorder_left+left_subtree_size-1] [postorder_left+left+subtree_size,postorder_right-1]
        root->left = _bulid(inorder, postorder, inorder_left, inorder_root - 1, postorder_left, postorder_left + left_subtree_size - 1);
        root->right = _bulid(inorder, postorder, inorder_root + 1, inorder_right, postorder_left + left_subtree_size, postorder_right - 1);
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return _bulid(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};


//https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submission