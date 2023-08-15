//https://leetcode.cn/problems/subtree-of-another-tree/

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
    bool isSameTree(struct TreeNode *root, struct TreeNode *subRoot) {
        if (root == nullptr && subRoot == nullptr)
            return true;

        if (root == nullptr || subRoot == nullptr)
            return false;

        if (root->val != subRoot->val)
            return false;

        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        // 递归每一个子树，判断每一个子树是否和subRoot是相同的二叉树
        // 如果root==null，返回false
        if (root == nullptr)
            return false;

        // 如果root和subRoot相同，则返回true
        if (isSameTree(root, subRoot))
            return true;

        // 递归每一个子树，只要有一个子树和subRoot相等，就说明subRoot是root的子树
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};