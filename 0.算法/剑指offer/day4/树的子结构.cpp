/* 描述
输入两棵二叉树A，B，判断B是不是A的子结构(不是子树)。 

示例1
输入：{8,8,7,9,2,#,#,#,#,4,7},{8,9,2}
返回值：true

示例2
输入：{1,2,3,4,5},{2,4}
返回值：true

示例3
输入：{1,2,3},{3,1}
返回值：false
*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};


class Solution {
public:
    bool isSubTree(TreeNode *root, TreeNode *subRoot) {
        //递归条件
        //subRoot == nullptr,说明subRoot走到了结束,那么说明是子结构
        if (subRoot == nullptr) {
            return true;
        }

        //subRoot!=nullptr，但是root==nullptr,说明subRoot不是root的子结构
        if (root == nullptr) {
            return false;
        }

        if (root->val != subRoot->val) {
            return false;
        }
        //左右树都想到才为true
        return isSubTree(root->left, subRoot->left) && isSubTree(root->right, subRoot->right);
    }

    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }

        //如果相等返回true
        if (isSubTree(pRoot1, pRoot2))
            return true;

        //递归左右子树
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};


//https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?