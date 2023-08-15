//https://leetcode.cn/problems/symmetric-tree/submissions/

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
    bool _isSymmetric(struct TreeNode *left, struct TreeNode *right) {
        // 两个都为NULL，对称
        if (left == nullptr && right == nullptr)
            return true;

        // 两个其中一个为NULL，一个不为NULL，不对称
        if (left == nullptr || right == nullptr)
            return false;

        // left的左孩子的值和right的值不相等，不对称
        if (left->val != right->val)
            return false;

        // 左子树的左孩子，和右子树的右孩子对比，然后左子树的右孩子和右子树的左孩子在对比
        return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        
        return _isSymmetric(root->left, root->right);
    }
};