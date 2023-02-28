#include <stddef.h>
// ����һ�������ͷ�ڵ�head��һ���ض�ֵx �������������зָ���ʹ������С��x�Ľڵ㶼�����ڴ��ڻ����x�Ľڵ�֮ǰ��

struct ListNode
{
    int val;
    struct ListNode *next;
};

// ��С��x�Ľڵ���뵽smallhead������x�Ľڵ�β�嵽bighead��Ȼ��������������
struct ListNode *partition(struct ListNode *head, int x)
{
    // ������β�壬ʹ��ͷ�ڵ㣬ע�⣺ֻҪ��β�壬���ô�ͷ�ڵ㣬������
    struct ListNode *smallhead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *smalltail = smallhead;
    struct ListNode *bighead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *bigtail = bighead;
    //bigtail��next����Ϊ���ó�NULL������������е����ֶ�������x����ôbigtail�Ͳ��ᱻβ�壬��ô����next�����ֵ��
    bigtail->next = NULL;
   
    struct ListNode *cur = head;

    // β�嵽��������
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

    // ������������ small�����β���ӵ�big�����ͷ�ڵ����һ��
    smalltail->next = bighead->next;
    // ���bigtail������next����ΪNULL
    bigtail->next = NULL;
    // ��ͷ�ڵ����������ͷ�ڵ����һ��

    head = smallhead->next;
    free(smallhead);
    free(bighead);
    return head;
}

// https://leetcode.cn/problems/partition-list/
