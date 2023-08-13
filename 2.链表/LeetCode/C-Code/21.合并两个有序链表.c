#include <stddef.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *newhead = NULL;
    struct ListNode *tail = NULL;
    // 思路：两个链表一起走，判断大小，将小的尾插到新链表中，有一个链表为空，则结束循环。剩下的链表判断是否为空，不为空直接链接到tail后面即可。
    // 如果两个链表其中有一个为空，那么循环进不去。 list1==NULL，return list2.  list2==NULL，return list1
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            if (newhead == NULL)
            {
                newhead = tail = list1;
            }
            else
            {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        }
        else
        {
            if (newhead == NULL)
            {
                newhead = tail = list2;
            }
            else
            {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }

    if (list1 != NULL)
    {
        // 如果newhead为空，说明上面条件没进去，说明list1和list2有一个为空。
        // list1为空，则返回list2  list2为空则返回list1/
        if (newhead == NULL)
        {
            return list1;
        }
        else // 如果newhead！=NULL 说明上面的循环条件为1，即两个链表都不为空。那么循环结束后，list1没有走向空，说明list1没有走完，直接将list1链接到tail后面
        {
            tail->next = list1;
        }
    }

    if (list2 != NULL)
    {
        // 如果newhead为空，说明上面条件没进去，说明list1和list2有一个为空。
        // list1为空，则返回list2  list2为空则返回list1/
        if (newhead == NULL)
        {
            return list2;
        }
        else // 如果newhead！=NULL 说明上面的循环条件为1，即两个链表都不为空。那么循环结束后，list2没有走向NULL，说明list2没有走完，直接将list2链接到tail后面
        {
            tail->next = list2;
        }
    }
    return newhead;
}

// https://leetcode.cn/problems/merge-two-sorted-lists/description/