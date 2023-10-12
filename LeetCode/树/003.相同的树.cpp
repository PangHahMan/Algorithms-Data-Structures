/* 
给你两棵二叉树的根节点p和q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
示例 1：
输入：p = [1,2,3], q = [1,2,3]
输出：true

示例 2：
输入：p = [1,2], q = [1,null,2]
输出：false

示例 3：
输入：p = [1,2,1], q = [1,1,2]
输出：false
*/

#include<vector>
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        //两边都为nullptr为相同树,递归到最后
        if (p == nullptr && q == nullptr) {
            return true;
        }

        //两者有一个为nullptr,则不是相同
        if (p == nullptr || q == nullptr) {
            return false;
        }

        //值不同,则不相同
        if (p->val != q->val) {
            return false;
        }

        //递归左右子树
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

//https://leetcode.cn/problems/same-tree/description/