/* 描述:
给你两个单链表的头节点headA和headB，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回null。

题目数据 保证整个链式结构中不存在环。
注意，函数返回结果后，链表必须保持其原始结构 。
*/

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

//https://leetcode.cn/problems/intersection-of-two-linked-lists/description/