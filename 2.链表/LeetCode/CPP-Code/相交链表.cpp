//https://leetcode.cn/problems/intersection-of-two-linked-lists/description/

#include <cmath>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//思路：计算两个链表各自的长度，计算差值，让长链表先走差值步，然后一起走，直到相等,找不到返回nullptr
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
};