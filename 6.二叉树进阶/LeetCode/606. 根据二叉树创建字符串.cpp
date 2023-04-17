struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <string>
using namespace std;
class Solution
{
public:
    string tree2str(TreeNode *root)
    {
        if (root == nullptr)
            return "";

        string str = to_string(root->val);
        // 1.走左子树，左子树两种情况，
        // 1是左子树为空，省略
        // 2是左子树为空，右子树不为空，则不省略
        if (root->left)
        {
            str += '(';
            str += tree2str(root->left);
            str += ')';
        }
     
        if (root->left == nullptr && root->right)
        {
            str += '(';
            str += "";
            str += ')';
        }

        //2.走右子树
        if (root->right)
        {
            str += '(';
            str += tree2str(root->right);
            str += ')';
        }

        return str;
    }
};

// https://leetcode.cn/problems/construct-string-from-binary-tree/