// �������ö������ĸ��ڵ�p��q ����дһ���������������������Ƿ���ͬ��
// ����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    // ��p��q��ΪNULL��ʱ�򣬷�����
    if (p == NULL && q == NULL)
        return true;

    // ����һ��ΪNULL �����ؼ�  ��������ΪNULL �����Ѿ��ж��ˣ����Կ�����ôд
    if (p == NULL || q == NULL)
        return false;

    // ����������������ֵ����ͬ������ж�˳������������Ϊp��q����ΪNULL���ᷢ����ָ�������
    // �����ǰ��Ҫ����p&&q
    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// https://leetcode.cn/problems/same-tree/