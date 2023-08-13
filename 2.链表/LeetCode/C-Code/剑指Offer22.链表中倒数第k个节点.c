#include <stddef.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *getKthFromEnd(struct ListNode *head, int k)
{
    // ˼·��˫ָ�룬��ָ������k������ָ�����ߣ���ָ�����ָ��������Ϊk����ָ���ߵ����Ϊ��ʱֹͣ����ʱ��ָ����ǵ�����k���ڵ�
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (k--)
    {
        // ���k�����˽ڵ�ĸ�������ô�ͷ��ؿա���fast����k-1�����ߵ���ʱ��˵���������������������if����Ҫд��fast = fast->nextǰ��
        if (fast == NULL)
        {
            return NULL;
        }
        fast = fast->next;
    }

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}
// https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/