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
        if(root == nullptr){
            return;
        }
        
        _postorderTraversal(root->left,res);
        _postorderTraversal(root->right,res);
          res.push_back(root->val);     
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        _postorderTraversal(root, res);
        return res;
    }
};

//https://leetcode.cn/problems/binary-tree-postorder-traversal/description/