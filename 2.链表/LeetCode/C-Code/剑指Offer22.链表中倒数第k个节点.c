#include <stddef.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *getKthFromEnd(struct ListNode *head, int k)
{
    // 思路：双指针，快指针先走k步，慢指针在走，快指针和满指针相差距离为k，快指针走到最后为空时停止，此时慢指针就是倒数第k个节点
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (k--)
    {
        // 如果k超过了节点的个数，那么就返回空。当fast先走k-1步就走到空时，说明超过了链表个数，所以if条件要写在fast = fast->next前面
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