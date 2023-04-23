struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <stack>
using namespace std;

// 非递归写法
// 后序是先走左子树，右子树，根。我们可以先走根，右子树，左子树，在逆置一下
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        if (root == nullptr)
        {
            return v;
        }

        while (cur || !st.empty())
        {
            while (cur)
            {
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->right;
            }

            TreeNode *top = st.top();
            st.pop();

            cur = top->left;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

/* 递归写法
class Solution
{
public:
    TreeNode *_postorder(vector<int> &v, TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        root->left = _postorder(v, root->left);
        root->right = _postorder(v, root->right);
        v.push_back(root->val);
        return root;
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        _postorder(v, root);
        return v;
    }
};
*/