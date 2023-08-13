//https://leetcode.cn/problems/linked-list-cycle/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 思路：快慢指针，慢指针走1步，快指针走两步。快指针先进环，满指针后进环，快指针追赶慢指针，追赶上说明带环，否则不带环
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            //先走在判断，因为初始时候都是head,会判错
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};