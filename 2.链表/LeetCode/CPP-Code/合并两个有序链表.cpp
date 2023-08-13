// https://leetcode.cn/problems/merge-two-sorted-lists/description/

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
        ListNode* guard = new ListNode();
        ListNode* tail = guard;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        while(cur1&&cur2){
            //取小的结点尾插到新链表后面
            if(cur1->val<cur2->val){
                tail->next = cur1;
                cur1 = cur1->next;
            }else{
                tail->next = cur2;
                cur2 = cur2->next;
            }
            tail = tail->next;
        }
        //将未遍历完的链表的剩余结点接到新链表后面
        if(cur1){
            tail->next = cur1;
        }else{
            tail->next = cur2;
        }

        return guard->next;
    }
};