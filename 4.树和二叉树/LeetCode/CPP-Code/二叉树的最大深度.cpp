//https://leetcode.cn/problems/maximum-depth-of-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        // 二叉树的最大深度，也就是说找左子树和右子树中最大的那个子树的深度
        // 递归条件是找到NULL为止
        if (root == nullptr) {
            return 0;
        }

        //如果跟的左右子树都为NULL 就返回1
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        // 递归左子树
        int depthleft = maxDepth(root->left);
        int depthright = maxDepth(root->right);
        return depthleft > depthright ? depthleft + 1 : depthright + 1;
    }
};