#include <stddef.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head)
{
    // 思路：快慢指针 一个走1步，一个走两步
    // 当链表个数为偶数，fast会走向NULL，链表个数为奇数，fast会走向最后一个节点
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    // 循环条件为，fast不为NULL,并且fast->next！=NULL
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// https://leetcode.cn/problems/middle-of-the-linked-list/description/