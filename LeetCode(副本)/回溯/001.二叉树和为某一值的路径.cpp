/*描述
输入一颗二叉树的根节点root和一个整数expectNumber，找出二叉树中结点值的和为expectNumber的所有路径。
1.该题路径定义为从树的根结点开始往下一直到叶子结点所经过的结点
2.叶子节点是指没有子节点的节点
3.路径只能从父节点到子节点，不能从子节点到父节点
4.总节点数目为n

如二叉树root为{10,5,12,4,7},expectNumber为22 
*/

#include <vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 辅助递归函数，用于在树中寻找满足条件的路径
    // root: 当前遍历的节点
    // target: 当前目标值
    // result: 用于储存满足条件的路径的二维向量
    // list: 用于储存当前路径的一维向量
    void _FindPath(TreeNode *root, int target, vector<vector<int>> &result, vector<int> &list) {
        // 如果当前节点为空，则直接返回，不进行后续操作
        if (!root) {
            return;
        }

        // 将当前节点的值添加到当前路径中
        list.push_back(root->val);
        // 从目标值中减去当前节点的值
        target -= root->val;

        // 如果当前节点为叶子节点且目标值已减至0，则将当前路径添加到结果中
        if (!root->left && !root->right && target == 0) {
            result.push_back(list);
        }

        // 递归遍历左子树和右子树
        _FindPath(root->left, target, result, list);
        _FindPath(root->right, target, result, list);

        // 回溯到上一个节点，从当前路径中删除最后一个节点
        list.pop_back();
    }

    // 主函数，用于调用辅助函数并返回结果
    // root: 二叉树的根节点
    // target: 目标和值
    vector<vector<int>> FindPath(TreeNode *root, int target) {
        // 定义一个二维向量用于储存所有满足条件的路径
        vector<vector<int>> result;
        
        // 如果根节点为空，则直接返回空的结果集
        if (!root) {
            return result;
        }

        // 定义一个一维向量用于储存当前路径
        vector<int> list;
        
        // 调用辅助函数开始查找
        _FindPath(root, target, result, list);

        // 返回最终找到的所有路径
        return result;
    }
};
//https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?