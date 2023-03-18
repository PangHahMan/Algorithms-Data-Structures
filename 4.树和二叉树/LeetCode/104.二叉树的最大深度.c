// ����һ�����������ҳ��������ȡ�
// �����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
// ˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    // �������������ȣ�Ҳ����˵�����������������������Ǹ����������
    // �ݹ��������ҵ�NULLΪֹ
    if (root == NULL)
    {
        return 0;
    }

    //�����������������ΪNULL �ͷ���1
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    // �ݹ�������
    int depthleft = maxDepth(root->left);
    int depthright = maxDepth(root->right);
    return depthleft > depthright ? depthleft + 1 : depthright + 1;
}

// https://leetcode.cn/problems/maximum-depth-of-binary-tree/