/* 
给定两个整数数组inorder和postorder ，其中inorder是二叉树的中序遍历， postorder是同一棵树的后序遍历，请你构造并返回这颗二叉树。

示例 1:
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]

示例 2:
输入：inorder = [-1], postorder = [-1]
输出：[-1]
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
    TreeNode *_buildTree(vector<int> &postorder, vector<int> &inorder, int &index, int begin, int end) {
        if (index < 0 || begin > end) {
            return nullptr;
        }
        // 还原根节点
        TreeNode *pRoot = new TreeNode(postorder[index]);
        // 在中序遍历结果中找根节点的位置，根节点左侧是是根的左子树，右侧的节点是根的右子树
        int rooti = end;
        while (inorder[rooti] != postorder[index]) {
            rooti--;
        }
        //找到了根节点在中序的位置,可以划分左右子树了
        index--;
        // 如果左子树存在，递归创建根节点的左子树
        pRoot->right = _buildTree(postorder, inorder, index, rooti + 1, end);
        pRoot->left = _buildTree(postorder, inorder, index, begin, rooti - 1);

        return pRoot;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        //后序从最后下标可以确认根,这一点根前序正好相反
        int index = postorder.size() - 1;
        return _buildTree(postorder, inorder, index, 0, inorder.size() - 1);
    }
};
