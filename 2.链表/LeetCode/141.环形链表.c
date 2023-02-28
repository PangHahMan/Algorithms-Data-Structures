#include <stddef.h>
#include <stdbool.h>
// ����һ�������ͷ�ڵ�head ���ж��������Ƿ��л���

struct ListNode
{
    int val;
    struct ListNode *next;
};

// ˼·������ָ�룬��ָ����1������ָ������������ָ���Ƚ�������ָ����������ָ��׷����ָ�룬׷����˵�����������򲻴���
bool hasCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        //�������жϣ���Ϊ��ʼʱ����head,���д�
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

//https://leetcode.cn/problems/linked-list-cycle/description/