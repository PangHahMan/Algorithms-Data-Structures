/* 
给你单链表的头节点head ，请你反转链表，并返回反转后的链表。
示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//采用整体头插法
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *newHead = nullptr;
        ListNode *cur = head;
        while (cur) {
            //记录cur的下一个结点,防止结点丢失
            ListNode *next = cur->next;
            //头插
            cur->next = newHead;
            newHead = cur;
            cur = next;
        }
        return newHead;
    }
};

//https://leetcode.cn/problems/reverse-linked-list/description/