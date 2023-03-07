#include < stddef.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    // ˼·��ͷ�壬��ÿһ����������ͷ�嵽�������У������γ��˷�ת
    struct ListNode *newhead = NULL;
    struct ListNode *cur = head;
    while (cur)
    {
        // ��¼cur����һ����㣬cur��nextָ��newhead��newhead���cur�γ��½�㣬cur������һ�����
        struct ListNode *nextnode = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = nextnode;
    }
    return newhead;
}

// https://leetcode.cn/problems/reverse-linked-list/submissions/