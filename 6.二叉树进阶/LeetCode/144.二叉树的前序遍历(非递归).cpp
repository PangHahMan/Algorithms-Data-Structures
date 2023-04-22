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
// 思路：左路节点入栈，然后访问左路节点的右子树
// 例如：8 3 1 入栈后，在访问1的右子树，如果1有左子树，那就继续入栈
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> v;
        TreeNode *cur = root;
        // 循环结束条件是栈为空，并且cur也等于空
        while (1)
        {
            // 也可以不用这么判断写在while里  while(cur || !st.empty())
            // 如果cur == nullptr 结果为0，那么判断st是否为空，如果st为空，那就是1，!st.empty为0，程序就退出了
            if (cur == nullptr && st.empty())
            {
                break;
            }
            // 左子树入栈,条件cur不为空，边遍历左子树边入vector
            while (cur)
            {
                // 前序左子树的节点放入vector中
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }

            // 左子树入栈后，带左子树的右子树,取栈顶
            TreeNode *top = st.top();
            st.pop();

            cur = top->right;
        }
        return v;
    }
};

/* 递归写法
class Solution
{
public:
    TreeNode *_preorder(vector<int> &v, TreeNode *root)
    {
        if (root == nullptr)
            return;
        v.push_back(root->val);
        root->left = _preorder(v, root->left);
        root->right = _preorder(v, root->right);
        return root;
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        _preorder(v, root);
        return v;
    }
};
 */

// https://leetcode.cn/problems/binary-tree-preorder-traversal/submissions/