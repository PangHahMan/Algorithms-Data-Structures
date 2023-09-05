/* 
给你单链表的头结点head ，请你找出并返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。

示例 1：
输入：head = [1,2,3,4,5]
输出：[3,4,5]
解释：链表只有一个中间结点，值为3。

示例 2：
输入：head = [1,2,3,4,5,6]
输出：[4,5,6]
解释：该链表有两个中间结点，值分别为3和4 ，返回第二个结点。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//快慢指针方式,快指针走两步,慢指针走1步，最后快指针走到最后,慢指针就是中间结点
class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

//https://leetcode.cn/problems/middle-of-the-linked-list/description/