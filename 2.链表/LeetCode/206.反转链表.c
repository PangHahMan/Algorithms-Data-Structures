#include < stddef.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    // 思路：头插，将每一个链表依次头插到新链表中，最后就形成了反转
    struct ListNode *newhead = NULL;
    struct ListNode *cur = head;
    while (cur)
    {
        // 记录cur的下一个结点，cur的next指向newhead，newhead变成cur形成新结点，cur继续下一个结点
        struct ListNode *nextnode = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = nextnode;
    }
    return newhead;
}

// https://leetcode.cn/problems/reverse-linked-list/submissions/