/* 
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
只有给定的树是单值二叉树时，才返回 true；否则返回 false。

示例 1：
输入：[1,1,1,1,1,null,1]
输出：true

示例 2：
输入：[2,2,2,5,2]
输出：false
*/

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
    bool isUnivalTree(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        //判断根节点是否跟左子树节点是否相同
        if (root->left && root->val != root->left->val) {
            return false;
        }

        //判断根节点是否跟右子树节点是否相同
        if (root->right && root->val != root->right->val) {
            return false;
        }

        //递归左右子树,两边子树都相同才是单值二叉树
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

//https://leetcode.cn/problems/univalued-binary-tree/description/