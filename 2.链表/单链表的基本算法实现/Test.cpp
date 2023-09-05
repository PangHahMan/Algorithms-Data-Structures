#include "SList.h"

void test1() {
    SListNode *phead = SListCreate(5);
    SListPushBack(&phead, 5);
    SListPushBack(&phead, 6);
    SListPushFront(&phead, -1);
    SListPushFront(&phead, -2);
    // 找6的位置
    SListNode *pos = SListFind(phead, 6);
    // 6的后面插入8
    SListInsertAfter(pos, 8);
    // SListEraseAfter(pos);
    pos = SListFind(phead, 8);
    // 8的前面插入7
    SListInsert(&phead, pos, 7);
    // 删除pos位置8
    SListErase(&phead, pos);
    SListPrint(phead);
}

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val) {
    struct ListNode *newhead, *tail;
    newhead = tail = NULL;
    struct ListNode *cur = head;
    while (cur) {
        if (cur->val == val) {
            cur = cur->next;
        } else {
            if (tail == NULL) {
                newhead = tail = cur;
                cur = cur->next;
            } else {
                tail->next = cur;
                cur = cur->next;
                tail = tail->next;
            }
        }
    }

    return newhead;
}

void test2() {
}

int main() {
    struct ListNode s1;
    struct ListNode s2;
    struct ListNode s3;
    struct ListNode s4;
    struct ListNode s5;
    struct ListNode s6;
    struct ListNode s7;
    s1.val = 1;
    s1.next = &s2;
    s2.val = 2;
    s2.next = &s3;
    s3.val = 6;
    s3.next = &s4;
    s4.val = 3;
    s4.next = &s5;
    s5.val = 4;
    s5.next = &s6;
    s6.val = 5;
    s6.next = &s7;
    s7.val = 6;
    s7.next = NULL;
    struct ListNode *newhead = removeElements(&s1, 6);

    return 0;
}
