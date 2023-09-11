/* 
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

示例 2：
输入：l1 = [], l2 = []
输出：[]

示例 3：
输入：l1 = [], l2 = [0]
输出：[0]
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *guard = new ListNode();   //加上头节点方便
        ListNode *tail = guard;
        ListNode *cur1 = list1;
        ListNode *cur2 = list2;
        //遍历cur1和cur2,找最小值插入到新链表后
        while (cur1 && cur2) {
            //取小的结点尾插到新链表后面
            if (cur1->val < cur2->val) {
                tail->next = cur1;
                cur1 = cur1->next;
            } else {
                tail->next = cur2;
                cur2 = cur2->next;
            }
            tail = tail->next;
        }
        //将未遍历完的链表的剩余结点接到新链表后面
        if (cur1) {
            tail->next = cur1;
        } else {
            tail->next = cur2;
        }

        return guard->next;
    }
};

//https://leetcode.cn/problems/merge-two-sorted-lists/description/