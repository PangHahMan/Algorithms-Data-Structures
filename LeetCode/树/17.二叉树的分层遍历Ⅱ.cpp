/* 
给你二叉树的根节点root ，返回其节点值自底向上的层序遍历 。（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]

示例 2：
输入：root = [1]
输出：[[1]]

示例 3：
输入：root = []
输出：[]
*/

#include <algorithm>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // 将root入队列，levelSize记录队列节点个数
        queue<TreeNode *> q;
        int levelSize = 0;
        // 1.先将根入队列,levelSize初始化为1
        if (root) {
            q.push(root);
            levelSize = 1;
        }
        // vv用于返回二维数组
        vector<vector<int>> vv;
        // 2. 出队列,带节点孩子
        while (!q.empty()) {
            // v用来记录一层的节点值
            vector<int> v;
            // 循环节点个数次
            while (levelSize--) {
                // 取队头的节点值，尾插到v中
                TreeNode *front = q.front();
                q.pop();
                v.push_back(front->val);
                // 带下一层左右孩子到队列中
                if (front->left) {
                    q.push(front->left);
                }

                if (front->right) {
                    q.push(front->right);
                }
            }
            // 将一层的值放到vv中
            vv.push_back(v);
            // 更新levelSize 也就是队列的size
            levelSize = q.size();
        }
        // 逆置vv
        reverse(vv.begin(), vv.end());
        return vv;
    }
};
//https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/