//https://leetcode.cn/problems/invert-binary-tree/
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
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode *leftTree = invertTree(root->left);
        TreeNode *rightTree = invertTree(root->right);

        root->left = rightTree;
        root->right = leftTree;

        return root;
    }
};