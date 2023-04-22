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

// 思路：左路节点入栈，然后访问左路节点的右子树
// 
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> v;
        TreeNode *cur = root;
        while (1)
        {
            if (cur == nullptr && st.empty())
            {
                break;
            }
            // 先左子树入栈，入栈完了在取栈顶入vector，前序是边遍历左子树边入vector
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            // 取栈顶，然后放到vector里，然后带右子树
            TreeNode *top = st.top();
            st.pop();
            v.push_back(top->val);

            // 右孩子
            cur = top->right;
        }
        return v;
    }
};

/* 递归方式
class Solution
{
public:
    TreeNode *_inorder(vector<int> &v, TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        root->left = _inorder(v, root->left);
        v.push_back(root->val);
        root->right = _inorder(v, root->right);

        return root;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        _inorder(v, root);
        return v;
    }
}; */