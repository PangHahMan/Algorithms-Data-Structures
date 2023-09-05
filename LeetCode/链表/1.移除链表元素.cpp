/* 
给你一个链表的头节点head和一个整数val ，请你删除链表中所有满足 Node.val == val 的节点，并返回新的头节点 。
示例 1：
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]

示例 2：
输入：head = [], val = 1
输出：[]

示例 3：
输入：head = [7,7,7,7], val = 7
输出：[]
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 思路：
当你需要移除链表中指定元素val时，你需要遍历链表，将不等于val的节点连接起来，从而构建一个新的链表。这个新链表中就不包含指定元素 val。 
*/
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *newHead = nullptr;
        ListNode *tail = nullptr;

        ListNode *cur = head;
        while (cur) {
            if (cur->val != val) {
                if (tail == nullptr) {
                    newHead = tail = cur;
                } else {
                    tail->next = cur;
                    tail = tail->next;
                }
            }
            cur = cur->next;// 不论当前节点是否符合条件，都要移动cur指针
        }

        if (tail != nullptr) {
            tail->next = nullptr;
        }

        return newHead;
    }
};


//https://leetcode.cn/problems/remove-linked-list-elements/description/