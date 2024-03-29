/* 描述
现有一链表的头指针ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。 
*/

//思路：先将两个链表分割(小于x的一个链表,大于等于x的一个链表)，然后在拼接
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Partition {
public:
    ListNode *partition(ListNode *pHead, int x) {
        if (pHead == nullptr) {
            return nullptr;
        }
        ListNode *lesshead, *lesstail;
        ListNode *greaterhead, *greatertail;
        //创建头节点
        lesshead = lesstail = new ListNode(-1);
        greaterhead = greatertail = new ListNode(-1);

        ListNode *cur = pHead;
        //分割链表
        while (cur) {
            if (cur->val < x) {
                lesstail->next = cur;
                lesstail = lesstail->next;
            } else {
                greatertail->next = cur;
                greatertail = greatertail->next;
            }
            cur = cur->next;
        }
        //两个链表连接，注意最后的节点置为nullptr
        lesstail->next = greaterhead->next;
        greatertail->next = nullptr;

        return lesshead->next;
    }
};

//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking