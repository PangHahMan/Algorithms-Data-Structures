struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <stack>
using namespace std;
class Solution
{
public:
    bool GetPath(TreeNode *root, TreeNode *x, stack<TreeNode *> &path)
    {
        if (root == nullptr)
            return false;

        path.push(root);
        if (root == x)
        {
            return true;
        }

        // 递归子树，返回为真，就返回真，用于判断和要找的路径是同一个路径
        // 也就是说要找的数的同一条路径返回结果都为真，而别的路径的返回结果为假，就pop掉
        if (GetPath(root->left, x, path))
        {
            return true;
        }

        if (GetPath(root->right, x, path))
        {
            return true;
        }

        // 这里比较关键，由下一级返回回来的为false才能走到这
        path.pop();

        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        stack<TreeNode *> pPath, qPath;
        GetPath(root, p, pPath);
        GetPath(root, q, qPath);
        while (pPath.size() != qPath.size())
        {
            if (pPath.size() > qPath.size())
            {
                pPath.pop();
            }
            else
            {
                qPath.pop();
            }
        }

        while (pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();
    }
};

// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/submissions/