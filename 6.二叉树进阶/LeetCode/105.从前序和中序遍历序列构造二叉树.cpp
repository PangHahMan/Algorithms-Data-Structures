struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;
class Solution {
public:
    TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder, int &i, int inbegin, int inend) {
        if (inbegin > inend) {
            return nullptr;
        }
        // 根据前序建立一个节点
        TreeNode *root = new TreeNode(preorder[i]);
        int rooti = inbegin;
        // 中序查找在前序的节点位置
        while (inorder[rooti] != preorder[i]) {
            rooti++;
        }
        
        i++;
        // 递归左右子树,分成两个区间[inbegin,rooti-1] rooti  [rooti+1,inend

        // 当子树递归到最后，只剩下一个inbegin为0,rooti-1 为-1.所以就产生了递归结束条件,inbegin>inend
        TreeNode *left = _buildTree(preorder, inorder, i, inbegin, rooti - 1);
        TreeNode *right = _buildTree(preorder, inorder, i, rooti + 1, inend);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // 根据preorder判断根节点
        int i = 0;
        return _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
    }
};

// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/