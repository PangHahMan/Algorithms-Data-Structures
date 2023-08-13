//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/* 思路：
1.首先找到中间结点
2.将中间结点后半部分倒置
3.分别从头结点和尾结点向中间遍历，检测在达到中间时刻之间val的值是否都相等 
*/


class PalindromeList {
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

    ListNode *reverseList(ListNode *head) {
        ListNode *newHead = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            //头插
            cur->next = newHead;
            newHead = cur;
            cur = next;
        }
        return newHead;
    }

    bool chkPalindrome(ListNode *A) {
        ListNode *middle = middleNode(A);     //中间节点
        ListNode *rhead = reverseList(middle);//反转
        //1 2 3 4 5   反转  1 2 5 4 3  注意2的next还是指向3
        while (rhead) {
            if (A->val != rhead->val) {
                return false;
            }
            A = A->next;
            rhead = rhead->next;
        }
        return true;
    }
};