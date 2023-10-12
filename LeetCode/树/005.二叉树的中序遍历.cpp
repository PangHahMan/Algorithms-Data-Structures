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

#include <stack>
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


//非递归版本
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        TreeNode *cur = root;
        if (!cur) {
            return v;
        }

        stack<TreeNode *> st;
        while (!st.empty() || cur) {
            //中序遍历,先push左子树
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode *top = st.top();
            st.pop();
            v.push_back(top->val);

            cur = top->right;
        }
        return v;
    }
};
//https://leetcode.cn/problems/binary-tree-inorder-traversal/description/