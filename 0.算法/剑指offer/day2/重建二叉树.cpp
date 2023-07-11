/* 描述
给定节点数为 n 的二叉树的前序遍历和中序遍历结果，请重建出该二叉树并返回它的头结点。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6} 

示例1
输入：[1,2,4,7,3,5,6,8],[4,7,2,1,5,3,8,6]
返回值：{1,2,3,4,#,5,6,#,7,#,#,8}    

示例2
输入：[1],[1]
返回值：{1}

示例3
输入：[1,2,3,4,5,6,7],[3,2,4,1,6,5,7]
返回值：{1,2,5,3,4,6,7}
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
    TreeNode *reConstructBinaryTreeCore(vector<int> &preOrder, int preLeft, int preRight, vector<int> &vinOrder, int vinLeft, int vinRight) {
        if (preLeft > preRight || vinLeft > vinRight) {
            return nullptr;
        }
        //用vector最左边的构建二叉树的根
        TreeNode *root = new TreeNode(preOrder[preLeft]);
        for (int i = vinLeft; i <= vinRight; i++) {
            //在中序序列中，找根节点，可以将数组划分为两部分
            if (preOrder[preLeft] == vinOrder[i]) {
                //找到了根在中序序列的位置
                //前序的第一个节点，是root，能将中序划分为两部分
                //一棵树，无论前，中，后怎么遍历，元素的个数是不变的
                //在实际遍历的时候，前，中，后序遍历，各种遍历方式左右子树的节点都是在一起的
                //所以这里重点是要想清楚下标问题
                //根据中序，我们能确认左子树的节点个数是：i - vinleft (没有从0开始哦)
                //所以，需要从preLeft+1，连续i - vinLeft个元素，就是左子树的前序序列
                root->left = reConstructBinaryTreeCore(preOrder, preLeft + 1, i - vinLeft + preLeft, vinOrder, vinLeft, i - 1);
                root->right = reConstructBinaryTreeCore(preOrder, i - vinLeft + preLeft + 1, preRight, vinOrder, i + 1, vinRight);
            }
        }
        return root;
    }
    TreeNode *reConstructBinaryTree(vector<int> &preOrder, vector<int> &vinOrder) {
        if (preOrder.empty() || vinOrder.empty()) {
            return nullptr;
        }
        //闭区间
        return reConstructBinaryTreeCore(preOrder, 0, preOrder.size() - 1, vinOrder, 0, vinOrder.size() - 1);
    }
};