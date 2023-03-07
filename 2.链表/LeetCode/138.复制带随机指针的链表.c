#include <stddef.h>
struct Node
{
    int val;
    struct Node *next;
    struct Node *random;
};

// ˼·������ÿһ���������棬���ø�ֵ��Ȼ����β�嵽������
struct Node *copyRandomList(struct Node *head)
{
    // 1.��������
    struct Node *cur = head;
    while (cur)
    {
        // copynode�Ǹ��ƵĽڵ�
        struct Node *copynode = (struct Node *)malloc(sizeof(struct Node));
        // nextnode�Ǽ�¼��һ���ڵ�
        struct Node *nextnode = cur->next;
        copynode->val = cur->val;

        cur->next = copynode;
        copynode->next = nextnode;

        cur = nextnode;
    }

    // 2.����random - ����ע��randomҪ�������ã���Ϊrandomָ������������ڵ�һ��ѭ��������������randomֵ
    cur = head;
    while (cur)
    {
        struct Node *copynode = cur->next;
        struct Node *nextnode = copynode->next;
        if (cur->random == NULL)
        {
            copynode->random = NULL;
        }
        else
        {
            copynode->random = cur->random->next;
        }
        cur = nextnode;
    }

    // β�嵽������
    cur = head;
    struct Node *copyhead = NULL;
    struct Node *copytail = NULL;

    while (cur)
    {
        // �Ҳ�������
        struct Node *copynode = cur->next;
        struct Node *nextnode = copynode->next;
        // β��
        if (copyhead == NULL)
        {
            copyhead = copytail = copynode;
        }
        else
        {
            copytail->next = copynode;
            copytail = copytail->next;
        }
        cur->next = nextnode;
        cur = nextnode;
    }
    return copyhead;
}
// https://leetcode.cn/problems/copy-list-with-random-pointer/