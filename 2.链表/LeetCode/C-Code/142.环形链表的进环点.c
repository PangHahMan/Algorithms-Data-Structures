#include <stddef.h>
// 给定一个链表的头节点head ，返回链表开始入环的第一个节点。 如果链表无环，则返回null。

struct ListNode
{
    int val;
    struct ListNode *next;
};

// 思路1
// 设slow还没进环的路程为K  进环后与fast追赶上slow为N slow的路程就等于K+N
// 设环周长为C，i为圈数 fast追赶上slow 走的路程就是K+C*i+N
// 已知slow*2 == fast    (K+N)*2 = K+C*i+N   可得K+N == C*i  可得K == C*i - N
// 这里i为多圈不好算，我们设i为1圈，那么对照图可以看出K == C-N
// C-N就是fast和slow相遇的节点
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;
    // 找环相遇节点
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            struct ListNode *meet = slow;
            // 不相等就继续走，走到相等位置
            while (meet != head)
            {
                meet = meet->next;
                head = head->next;
            }
            return meet;
        }
    }
    return NULL;
}

// 思路2  找相交链表
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

struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;
    // 找环相遇节点
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            struct ListNode *meet = slow;
            //将meet->next保存到其他节点，在将meet->next设为空，以防找相交链表永远死循环
            struct ListNode *otherNode = meet->next;
            return getIntersectionNode(head, otherNode);
        }
    }
    return NULL;
}

// https://leetcode.cn/problems/linked-list-cycle-ii/description/
