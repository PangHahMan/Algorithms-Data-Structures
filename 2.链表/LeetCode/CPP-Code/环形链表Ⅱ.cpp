//https://leetcode.cn/problems/linked-list-cycle-ii/description/

#include <cmath>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0, countB = 0;
        ListNode *curA = headA;
        ListNode *curB = headB;
        //计算curA的节点个数
        while (curA) {
            countA++;
            curA = curA->next;
        }
        //计算curB的节点个数
        while (curB) {
            countB++;
            curB = curB->next;
        }
        //计算差值
        int gap = abs(countA - countB);
        //让长的哪个链表先走gap步
        ListNode *longList = headA;
        ListNode *shortList = headB;
        if (countA < countB) {
            longList = headB;
            shortList = headA;
        }
        //长链表先走
        while (gap--) {
            longList = longList->next;
        }
        //一起走，直到相等
        while (longList && shortList) {
            if (longList == shortList) {
                return longList;
            }
            longList = longList->next;
            shortList = shortList->next;
        }
        return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        // 找环相遇节点
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                //相遇点
                ListNode *meet = slow;
                //将meet->next保存到其他节点，在将meet->next设为空，以防找相交链表永远死循环
                ListNode *otherNode = meet->next;
                //头节点和meet的相交链表就是入环口
                return getIntersectionNode(head, otherNode);
            }
        }
        return nullptr;
    }
};