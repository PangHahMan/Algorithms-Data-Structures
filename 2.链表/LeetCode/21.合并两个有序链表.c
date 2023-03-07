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
    // ˼·����������һ���ߣ��жϴ�С����С��β�嵽�������У���һ������Ϊ�գ������ѭ����ʣ�µ������ж��Ƿ�Ϊ�գ���Ϊ��ֱ�����ӵ�tail���漴�ɡ�
    // �����������������һ��Ϊ�գ���ôѭ������ȥ�� list1==NULL��return list2.  list2==NULL��return list1
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
        // ���newheadΪ�գ�˵����������û��ȥ��˵��list1��list2��һ��Ϊ�ա�
        // list1Ϊ�գ��򷵻�list2  list2Ϊ���򷵻�list1/
        if (newhead == NULL)
        {
            return list1;
        }
        else // ���newhead��=NULL ˵�������ѭ������Ϊ1��������������Ϊ�ա���ôѭ��������list1û������գ�˵��list1û�����ֱ꣬�ӽ�list1���ӵ�tail����
        {
            tail->next = list1;
        }
    }

    if (list2 != NULL)
    {
        // ���newheadΪ�գ�˵����������û��ȥ��˵��list1��list2��һ��Ϊ�ա�
        // list1Ϊ�գ��򷵻�list2  list2Ϊ���򷵻�list1/
        if (newhead == NULL)
        {
            return list2;
        }
        else // ���newhead��=NULL ˵�������ѭ������Ϊ1��������������Ϊ�ա���ôѭ��������list2û������NULL��˵��list2û�����ֱ꣬�ӽ�list2���ӵ�tail����
        {
            tail->next = list2;
        }
    }
    return newhead;
}

// https://leetcode.cn/problems/merge-two-sorted-lists/description/