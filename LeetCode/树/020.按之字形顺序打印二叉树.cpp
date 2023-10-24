/* 描述
给定一个二叉树，返回该二叉树的之字形层序遍历，（第一层从左向右，下一层从右向左，一直这样交替）
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <deque>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> Print(TreeNode *pRoot) {
        vector<vector<int>> result; // 存储最终结果的二维数组
        if (!pRoot) { // 如果根节点为空，直接返回空数组
            return result;
        }
        deque<TreeNode *> dq; // 使用deque存储每一层的节点
        dq.push_back(pRoot);
        bool leftToRight = true; // 初始方向从左向右

        while (!dq.empty()) {
            int size = dq.size(); // 当前层的节点数量
            vector<int> level; // 存储当前层遍历结果的数组
            
            // 处理一层的节点
            while (size--) {
                if (leftToRight) { // 从左向右遍历
                    TreeNode *node = dq.front(); // 取队头节点
                    dq.pop_front(); // 从队列中移除节点
                    level.push_back(node->val);
                    if (node->left) { // 将左子节点加入队列末尾
                        dq.push_back(node->left);
                    }
                    if (node->right) { // 将右子节点加入队列末尾
                        dq.push_back(node->right);
                    }
                } else { // 从右向左遍历
                    TreeNode *node = dq.back(); // 取队尾节点
                    dq.pop_back(); // 从队列中移除节点
                    level.push_back(node->val); 
                    
                    // 注意：这里因为是取队尾，所以带左右孩子需要倒序插入到队头
                    if (node->right) { // 将右子节点插入队列头部
                        dq.push_front(node->right);
                    }
                    if (node->left) { // 将左子节点插入队列头部
                        dq.push_front(node->left);
                    }
                }
            }
            result.push_back(level); // 将当前层的遍历结果加入最终结果数组
            leftToRight = !leftToRight; // 改变遍历方向
        }

        return result;
    }
};


//https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?