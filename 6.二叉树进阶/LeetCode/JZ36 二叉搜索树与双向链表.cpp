struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};

class Solution
{
public:
    void InOrderConvert(TreeNode *cur, TreeNode *&prev)
    {
        // 递归结束条件，节点为nullptr则返回
        if (cur == nullptr)
            return;
        // 要链接最左边的节点，链接最开始的prev，那么递归左子树到最左节点
        InOrderConvert(cur->left, prev);
        // 链接nnullptr
        cur->left = prev;
        // 如果prev!=nulllptr则链接right为cur,
        if (prev)
        {
            // 需要上级的prev来链接，所以需要引用调用
            prev->right = cur;
        }
        // 更新prev
        prev = cur;
        // 递归右子树
        InOrderConvert(cur->right, prev);
    }

    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        // 如果树为nullptr，直接返回nullptr
        if (pRootOfTree == nullptr)
        {
            return nullptr;
        }

        // prev初始化为nullptr,由二叉搜索树的最左边节点，也就是最小的节点链接的left
        TreeNode *prev = nullptr;
        InOrderConvert(pRootOfTree, prev);

        TreeNode *head = pRootOfTree;
        // 找头，也就是最左边的节点
        while (head->left)
        {
            head = head->left;
        }
        return head;
    }
};

// https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking