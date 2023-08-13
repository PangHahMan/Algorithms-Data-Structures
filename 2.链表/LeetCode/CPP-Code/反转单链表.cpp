struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *newHead = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            //头插
            cur->next = newHead;
            newHead = cur;
            cur = next;
        }
        return newHead;
    }
};