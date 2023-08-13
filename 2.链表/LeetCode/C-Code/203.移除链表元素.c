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
        // 如果cur等于val 就找下一个，不尾插，cur不等于val就尾插到tail后面
        if (cur->val == val) {
            cur = cur->next;
        } else {
            // 如果tail==NULL时，说明无法尾插，直接赋值。然后cur走下一个，tail生成了第一个结点
            if (tail == NULL) {
                newhead = tail = cur;
                cur = cur->next;
            } else// tail不为空时，就正常尾插。
            {
                tail->next = cur;
                cur = cur->next;
                tail = tail->next;
            }
        }
    }
    // 尾插到最后，要将tail置为NULL
    if (tail != NULL) {
        tail->next = NULL;
    }
    return newhead;
}

// https://leetcode.cn/problems/remove-linked-list-elements/submissions/