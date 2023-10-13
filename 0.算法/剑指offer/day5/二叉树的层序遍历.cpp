/* 
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]

示例 2：
输入：root = [1]
输出：[[1]]

示例 3：
输入：root = []
输出：[]
*/

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
    vector<vector<int>> levelOrder(TreeNode *root) {
        // 将root入队列，levelSize记录队列节点个数
        queue<TreeNode *> q;
        int levelSize = 0;
        // 1.先将根入队列,levelSize初始化为1
        if (root) {
            q.push(root);
            levelSize = 1;
        }
        //vv用于返回二维数组
        vector<vector<int>> vv;
        //2. 出队列,带节点孩子
        while (!q.empty()) {
            //v用来记录一层的节点值
            vector<int> v;
            //levelSize 1层的个数
            while (levelSize--) {
                //取队头的节点值，尾插到v中
                TreeNode *front = q.front();
                q.pop();
                v.push_back(front->val);
                //带下一层左右孩子到队列中
                if (front->left) {
                    q.push(front->left);
                }

                if (front->right) {
                    q.push(front->right);
                }
            }
            //将一层的值放到vv中
            vv.push_back(v);
            //更新levelSize 也就是队列的size
            levelSize = q.size();
        }
        return vv;
    }
};


//如果是倒着遍历，那么就直接将vv,逆置reverse
//https://leetcode.cn/problems/binary-tree-level-order-traversal/


//牛客版本 - 返回的是一维数组，不用定义levelSize记录一层的个数
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> v;
        if (!root) {
            return v;
        }
        //定义一个队列
        queue<TreeNode *> q;
        int levelSize = 0;
        if (root) {
            q.push(root);
            levelSize = 1;
        }

        while (!q.empty()) {
            TreeNode *front = q.front();
            v.push_back(front->val);
            q.pop();

            if (front->left) {
                q.push(front->left);
            }

            if (front->right) {
                q.push(front->right);
            }
        }

        return v;
    }
};

//https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?