/* 
描述：
输入一个链表，输出该链表中倒数第k个结点。
示例1
输入：1,{1,2,3,4,5}
返回值：{5}
*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

//思路：快慢指针，让快指针先走k步，超过k步直接返回nullptr,然后再一起走,直到fast为nullptr
class Solution {
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        ListNode *slow = pListHead;
        ListNode *fast = pListHead;

        while (k--) {
            if (fast == nullptr) {
                //k大于了整个链表的长度 就返回nullptr
                return nullptr;
            }
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking