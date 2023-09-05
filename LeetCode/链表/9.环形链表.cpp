/* 
给你一个链表的头节点head ，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪next指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
如果链表中存在环 ，则返回true 。 否则，返回false 。
*/

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

//https://leetcode.cn/problems/linked-list-cycle/description/