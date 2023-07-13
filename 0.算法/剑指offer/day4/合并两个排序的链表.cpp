/* 描述
输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。 

示例1
输入：{1,3,5},{2,4,6}
返回值：{1,2,3,4,5,6}

示例2
输入：{},{}
返回值：{}

示例3
输入：{-1,2,4},{1,3,4}
返回值：{-1,1,2,3,4,4}
*/


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//思路1归并
class Solution {
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        //合并前，先判定,如果其中有一个为nullptr,那么结果就是另外一个链表
        if (pHead1 == nullptr) {
            return pHead2;
        }

        if (pHead2 == nullptr) {
            return pHead1;
        }

        ListNode *newhead = nullptr;
        ListNode *tail = nullptr;
        //合并中,无非是比较各自首节点谁小，就把该节点从原链表中删除，在尾插到新节点处，比较中，两个链表任何一个都不能为空

        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                //newhead为nullptr说明是第一次插入
                if (newhead == nullptr) {
                    newhead = tail = pHead1;
                } else {
                    //尾插新链表
                    tail->next = pHead1;
                    tail = tail->next;
                }
                //更新链表头
                pHead1 = pHead1->next;
            } else {
                if (newhead == nullptr) {
                    newhead = tail = pHead2;
                } else {
                    tail->next = pHead2;
                    tail = tail->next;
                }
                pHead2 = pHead2->next;
            }
        }
        //遍历完，假如两个链表长度不同,一个为nullptr提前跳出
        if (pHead1 != nullptr) {
            tail->next = pHead1;
        }

        if (pHead2 != nullptr) {
            tail->next = pHead2;
        }

        return newhead;
    }
};


//思路2：递归
class Solution {
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        //合并前，先判定,如果其中有一个为nullptr,那么结果就是另外一个链表
        if (pHead1 == nullptr) {
            return pHead2;
        }

        if (pHead2 == nullptr) {
            return pHead1;
        }

        ListNode *newhead = nullptr;

        if (pHead1->val < pHead2->val) {
            newhead = pHead1;
            pHead1 = pHead1->next;
        } else {
            newhead = pHead2;
            pHead2 = pHead2->next;
        }

        newhead->next = Merge(pHead1, pHead2);
        return newhead;
    }
};

//https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?