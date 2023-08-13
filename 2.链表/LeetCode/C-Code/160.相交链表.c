#include <stddef.h>
// ���������������ͷ�ڵ�headA��headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬����null��

struct ListNode
{
    int val;
    struct ListNode *next;
};

// ˼·��������������ĸ�����Ȼ�����ó����������߲�ֵ��Ȼ����һ���ߣ�ֱ��headA==headB
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    int i = 0, j = 0;
    struct ListNode *curA = headA;
    struct ListNode *curB = headB;
    // ����A������
    while (curA)
    {
        i++;
        curA = curA->next;
    }
    // ����B������
    while (curB)
    {
        j++;
        curB = curB->next;
    }
    // �����ֵ
    int gap = abs(i - j);
    // ��������AΪ����BΪ�̣����i<j,���෴
    struct ListNode *longList = headA;
    struct ListNode *shortList = headB;
    if (i < j)
    {
        longList = headB;
        shortList = headA;
    }

    // �ó�������gap��
    while (gap--)
    {
        longList = longList->next;
    }
    // ѭ�����ж��Ƿ���ȣ���ȷ��أ�ѭ������������ȣ�����NULL
    while (longList && shortList)
    {
        if (longList == shortList)
        {
            return longList;
        }
        longList = longList->next;
        shortList = shortList->next;
    }
    return NULL;
}

//https://leetcode.cn/problems/intersection-of-two-linked-lists/description/