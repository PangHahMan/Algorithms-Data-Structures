#include <stdbool.h>
#include <stddef.h>
// 给你一个单链表的头节点head ，请你判断该链表是否为回文链表。如果是，返回true；否则，返回false 。
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *newhead = NULL;
    struct ListNode *cur = head;
    while (cur)
    {
        struct ListNode *nextnode = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = nextnode;
    }
    return newhead;
}


bool isPalindrome(struct ListNode *head)
{
    //思路：1.找中间节点，中间节点后面的节点反转。然后在判断左边节点和右边是否相等
    struct ListNode* mid = middleNode(head);
    struct ListNode* rhead = reverseList(mid);
    //右边链表为空，则停止
    while(rhead)
    {
        if(head->val!=rhead->val)
        {
            return false;
        }
        head = head->next;
        rhead = rhead->next;
    }
    return true;
}

// https://leetcode.cn/problems/palindrome-linked-list/