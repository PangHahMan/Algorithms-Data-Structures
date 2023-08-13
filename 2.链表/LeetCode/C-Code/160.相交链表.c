#include <stddef.h>
// 给你两个单链表的头节点headA和headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回null。

struct ListNode
{
    int val;
    struct ListNode *next;
};

// 思路；计算两个链表的个数，然后在让长的链表先走差值，然后在一起走，直到headA==headB
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    int i = 0, j = 0;
    struct ListNode *curA = headA;
    struct ListNode *curB = headB;
    // 计算A链表长度
    while (curA)
    {
        i++;
        curA = curA->next;
    }
    // 计算B链表长度
    while (curB)
    {
        j++;
        curB = curB->next;
    }
    // 计算差值
    int gap = abs(i - j);
    // 假设链表A为长，B为短，如果i<j,则相反
    struct ListNode *longList = headA;
    struct ListNode *shortList = headB;
    if (i < j)
    {
        longList = headB;
        shortList = headA;
    }

    // 让长的先走gap步
    while (gap--)
    {
        longList = longList->next;
    }
    // 循环，判断是否相等，相等返回，循环结束还不相等，返回NULL
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