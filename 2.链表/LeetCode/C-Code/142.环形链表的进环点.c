#include <stddef.h>
// ����һ�������ͷ�ڵ�head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻�null��

struct ListNode
{
    int val;
    struct ListNode *next;
};

// ˼·1
// ��slow��û������·��ΪK  ��������fast׷����slowΪN slow��·�̾͵���K+N
// �軷�ܳ�ΪC��iΪȦ�� fast׷����slow �ߵ�·�̾���K+C*i+N
// ��֪slow*2 == fast    (K+N)*2 = K+C*i+N   �ɵ�K+N == C*i  �ɵ�K == C*i - N
// ����iΪ��Ȧ�����㣬������iΪ1Ȧ����ô����ͼ���Կ���K == C-N
// C-N����fast��slow�����Ľڵ�
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;
    // �һ������ڵ�
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            struct ListNode *meet = slow;
            // ����Ⱦͼ����ߣ��ߵ����λ��
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

// ˼·2  ���ཻ����
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    int i = 0, j = 0;
    struct ListNode *curA = headA;
    struct ListNode *curB = headB;
    // ����A������
    while (curA)
    {
        i++;
        curA = curA->next;
    }
    // ����B������
    while (curB)
    {
        j++;
        curB = curB->next;
    }
    // �����ֵ
    int gap = abs(i - j);
    // ��������AΪ����BΪ�̣����i<j,���෴
    struct ListNode *longList = headA;
    struct ListNode *shortList = headB;
    if (i < j)
    {
        longList = headB;
        shortList = headA;
    }

    // �ó�������gap��
    while (gap--)
    {
        longList = longList->next;
    }
    // ѭ�����ж��Ƿ���ȣ���ȷ��أ�ѭ������������ȣ�����NULL
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
    // �һ������ڵ�
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            struct ListNode *meet = slow;
            //��meet->next���浽�����ڵ㣬�ڽ�meet->next��Ϊ�գ��Է����ཻ������Զ��ѭ��
            struct ListNode *otherNode = meet->next;
            return getIntersectionNode(head, otherNode);
        }
    }
    return NULL;
}

// https://leetcode.cn/problems/linked-list-cycle-ii/description/
