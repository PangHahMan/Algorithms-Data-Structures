#include <stddef.h>
// 给你一个链表的头节点head和一个特定值x ，请你对链表进行分隔，使得所有小于x的节点都出现在大于或等于x的节点之前。

struct ListNode
{
    int val;
    struct ListNode *next;
};

// 将小于x的节点插入到smallhead，大于x的节点尾插到bighead。然后将两个链表连接
struct ListNode *partition(struct ListNode *head, int x)
{
    // 这里用尾插，使用头节点，注意：只要是尾插，就用带头节点，更方便
    struct ListNode *smallhead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *smalltail = smallhead;
    struct ListNode *bighead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *bigtail = bighead;
    //bigtail的next必须为设置成NULL，否则如果所有的数字都不大于x，那么bigtail就不会被尾插，那么他的next是随机值。
    bigtail->next = NULL;
   
    struct ListNode *cur = head;

    // 尾插到两个链表
    while (cur)
    {
        if (cur->val < x)
        {
            smalltail->next = cur;
            smalltail = smalltail->next;
        }
        else
        {
            bigtail->next = cur;
            bigtail = bigtail->next;
        }
        cur = cur->next;
    }

    // 连接两个链表 small链表的尾连接到big链表的头节点的下一个
    smalltail->next = bighead->next;
    // 最后将bigtail的最后的next设置为NULL
    bigtail->next = NULL;
    // 带头节点的链表，返回头节点的下一个

    head = smallhead->next;
    free(smallhead);
    free(bighead);
    return head;
}

// https://leetcode.cn/problems/partition-list/
