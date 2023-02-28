#include <stdbool.h>
#include <stddef.h>
// ����һ���������ͷ�ڵ�head �������жϸ������Ƿ�Ϊ������������ǣ�����true�����򣬷���false ��
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
    //˼·��1.���м�ڵ㣬�м�ڵ����Ľڵ㷴ת��Ȼ�����ж���߽ڵ���ұ��Ƿ����
    struct ListNode* mid = middleNode(head);
    struct ListNode* rhead = reverseList(mid);
    //�ұ�����Ϊ�գ���ֹͣ
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