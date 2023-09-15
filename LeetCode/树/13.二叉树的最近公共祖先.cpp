/* 
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
*/

#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 获取从根节点到目标节点的路径，将路径保存在给定的栈中
    bool GetPath(TreeNode *root, TreeNode *x, stack<TreeNode *> &path) {
        if (root == nullptr)
            return false;

        path.push(root);
        if (root == x) {
            return true;// 找到目标节点，返回真
        }

        // 在左子树中递归查找目标节点
        if (GetPath(root->left, x, path)) {
            return true;// 如果在左子树中找到，返回真
        }

        // 在右子树中递归查找目标节点
        if (GetPath(root->right, x, path)) {
            return true;// 如果在右子树中找到，返回真
        }

        // 如果左右子树都没有找到目标节点，将当前节点从路径中移除
        path.pop();

        return false;// 未找到目标节点，返回假
    }

    // 找到两个节点的最低公共祖先
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        stack<TreeNode *> pPath, qPath;

        // 获取根节点到p的路径
        GetPath(root, p, pPath);
        // 获取根节点到q的路径
        GetPath(root, q, qPath);

        // 对比两个路径，使得路径长度相同
        while (pPath.size() != qPath.size()) {
            if (pPath.size() > qPath.size()) {
                pPath.pop();// 移除较长路径的顶部节点
            } else {
                qPath.pop();// 移除较长路径的顶部节点
            }
        }

        // 同时向上遍历两条路径，直到找到最低公共祖先
        while (pPath.top() != qPath.top()) {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();// 返回最低公共祖先节点
    }
};
//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/