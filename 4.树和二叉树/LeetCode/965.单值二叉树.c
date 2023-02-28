#include <stdlib.h>
#include <stdbool.h>
// ���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
// ֻ�и��������ǵ�ֵ������ʱ���ŷ���true�����򷵻�false��
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isUnivalTree(struct TreeNode *root)
{
    // ˼·  ���������������͸�����������ֵ����ȣ��ݹ����������rootΪNULL
    // 1.���������ĵݹ飬�����������ȵ� ֱ�ӷ���false
    // 2.���������ĵݹ飬�����������ȵ� ֱ�ӷ���false
    // 3.�ݹ��������ߵ�NULL �ڷ��ؽ�����ߵ�NULL �ͷ���true
    if (root == NULL)
    {
        return true;
    }
    // ����Ҫע��root->left��root->right ����ΪNULL
    if (root->left && root->val != root->left->val)
        return false;

    if (root->right && root->val != root->right->val)
        return false;

    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

// https://leetcode.cn/problems/univalued-binary-tree/