/* 描述
对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

测试样例：
1->2->2->1
返回：true
*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include <stack>
using namespace std;

//思路：利用栈，先push到栈中,如果链表的值和栈顶相等则出栈,最后判断栈是否为空即可判断是否回文
class PalindromeList {
public:
    bool chkPalindrome(ListNode *A) {
        stack<int> st;
        ListNode *cur = A;
        st.push(cur->val);
        while (cur->next) {
            if (cur->next->val == st.top()) {
                st.pop();
            } else {
                st.push(cur->next->val);
            }
            cur = cur->next;
        }
        return st.empty();
    }
};

//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking