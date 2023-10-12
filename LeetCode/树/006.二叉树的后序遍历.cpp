/* 
给你一棵二叉树的根节点root ，返回其节点值的后序遍历 。

示例 1：
输入：root = [1,null,2,3]
输出：[3,2,1]

示例 2：
输入：root = []
输出：[]

例 3：
输入：root = [1]
输出：[1]
*/

#include <algorithm>
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
    void _postorderTraversal(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }

        _postorderTraversal(root->left, res);
        _postorderTraversal(root->right, res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        _postorderTraversal(root, res);
        return res;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        TreeNode *cur = root;
        vector<int> v;
        stack<TreeNode *> st;
        if (root == nullptr) {
            return v;
        }

        while (!st.empty() || cur) {
            //后序遍历左右根 可以先根右左,存放在v向量最后翻转即可
            while (cur) {
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->right;
            }

            //左子树
            TreeNode *top = st.top();
            st.pop();

            cur = top->left;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

//https://leetcode.cn/problems/binary-tree-postorder-traversal/description/