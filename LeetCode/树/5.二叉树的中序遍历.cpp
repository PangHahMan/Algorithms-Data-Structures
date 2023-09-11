/* 
给定一个二叉树的根节点root ，返回它的中序遍历。

示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]
*/

#include <vector>
using namespace std;
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
    void _inorderTraversal(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }

        _inorderTraversal(root->left, res);
        res.push_back(root->val);
        _inorderTraversal(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        _inorderTraversal(root, res);
        return res;
    }
};

//https://leetcode.cn/problems/binary-tree-inorder-traversal/description/