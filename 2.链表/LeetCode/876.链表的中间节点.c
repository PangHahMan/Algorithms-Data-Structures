#include <stddef.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head)
{
    // ˼·������ָ�� һ����1����һ��������
    // ���������Ϊż����fast������NULL���������Ϊ������fast���������һ���ڵ�
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    // ѭ������Ϊ��fast��ΪNULL,����fast->next��=NULL
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// https://leetcode.cn/problems/middle-of-the-linked-list/description/