/* 
给你二叉树的根节点root ，返回它节点值的 前序 遍历。
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
    void preorder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};


//非递归版本
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode *cur = root;
        vector<int> v;
        if (cur == nullptr) {
            return v;
        }

        stack<TreeNode *> st;
        while (!st.empty() || cur) {
            // 左子树入栈,条件cur不为空
            while (cur) {
                // 前序左子树的节点放入vector中
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }

            // 左子树入栈后，带左子树的右子树,取栈顶
            TreeNode *top = st.top();
            st.pop();

            cur = top->right;
        }
        return v;
    }
};
//https://leetcode.cn/problems/binary-tree-preorder-traversal/description/