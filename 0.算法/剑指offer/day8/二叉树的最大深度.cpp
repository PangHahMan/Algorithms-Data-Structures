/* 
给定一个二叉树 root ，返回其最大深度。
二叉树的最大深度是指从根节点到最远叶子节点的最长路径上的节点数。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：3

示例 2：
输入：root = [1,null,2]
输出：2
*/
#include<algorithm>
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
    int maxDepth(TreeNode *root) {
        //根为空,深度为0
        if (root == nullptr) {
            return 0;
        }

        //根的左右子树为空,深度为1
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int leftTree = maxDepth(root->left);
        int rightTree = maxDepth(root->right);
        return leftTree >= rightTree ? leftTree + 1 : rightTree + 1;
    }
};

//写法2
class Solution {
public:
    int maxDepth(TreeNode *root) {
        //根为空,深度为0
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
//https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/