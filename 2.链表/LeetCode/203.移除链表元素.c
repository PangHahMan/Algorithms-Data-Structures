#include <stddef.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val) {
    struct ListNode *newhead, *tail;
    newhead = tail = NULL;
    struct ListNode *cur = head;
    while (cur) {
        // ���cur����val ������һ������β�壬cur������val��β�嵽tail����
        if (cur->val == val) {
            cur = cur->next;
        } else {
            // ���tail==NULLʱ��˵���޷�β�壬ֱ�Ӹ�ֵ��Ȼ��cur����һ����tail�����˵�һ�����
            if (tail == NULL) {
                newhead = tail = cur;
                cur = cur->next;
            } else// tail��Ϊ��ʱ��������β�塣
            {
                tail->next = cur;
                cur = cur->next;
                tail = tail->next;
            }
        }
    }
    // β�嵽���Ҫ��tail��ΪNULL
    if (tail != NULL) {
        tail->next = NULL;
    }
    return newhead;
}

// https://leetcode.cn/problems/remove-linked-list-elements/submissions/