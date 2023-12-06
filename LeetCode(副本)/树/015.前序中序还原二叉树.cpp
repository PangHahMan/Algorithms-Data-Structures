/* 
给定两个整数数组preorder和inorder，其中preorder是二叉树的先序遍历， inorder是同一棵树的中序遍历，请构造二叉树并返回其根节点。

示例 1:
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]

示例 2:
输入: preorder = [-1], inorder = [-1]
输出: [-1]
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
    //begin end 表示中序中的位置
    TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder, int &i, int begin, int end) {
        //递归结束条件
        if(begin > end || i > inorder.size()){
            return nullptr;
        }
        
        //前序建立一个根
        TreeNode *root = new TreeNode(preorder[i]);
        //定义一个变量用来标识根在中序的位置，从而确认左右子树
        int rooti = begin;
        while (inorder[rooti] != preorder[i]) {
            rooti++;
        }
        i++;//更新i,下一个前序
        //rooti就是根在中序的位置
        //递归左右子树,分成两个区间[begin,rooti-1] rooti  [rooti+1,end]
        root->left = _buildTree(preorder, inorder, i, begin, rooti - 1);
        root->right = _buildTree(preorder, inorder, i, rooti + 1, end);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        //可以通过前序来判断根结点
        int i = 0;  //i表示前序的位置
        return _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
    }
};

//https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/