/* 
给定一个链表的头节点head，返回链表开始入环的第一个节点。 如果链表无环，则返回null。
如果链表中有某个节点，可以通过连续跟踪next指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数pos来表示链表尾连接到链表中的位置（索引从0开始）。如果pos是-1，则在该链表中没有环。注意：pos不作为参数进行传递，仅仅是为了标识链表的实际情况。
不允许修改链表。
*/

#include <cmath>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//找环相遇节点,然后在找相交节点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0, countB = 0;
        ListNode *curA = headA;
        ListNode *curB = headB;
        //计算curA的节点个数
        while (curA) {
            countA++;
            curA = curA->next;
        }
        //计算curB的节点个数
        while (curB) {
            countB++;
            curB = curB->next;
        }
        //计算差值
        int gap = abs(countA - countB);
        //让长的哪个链表先走gap步
        ListNode *longList = headA;
        ListNode *shortList = headB;
        if (countA < countB) {
            longList = headB;
            shortList = headA;
        }
        //长链表先走
        while (gap--) {
            longList = longList->next;
        }
        //一起走，直到相等
        while (longList && shortList) {
            if (longList == shortList) {
                return longList;
            }
            longList = longList->next;
            shortList = shortList->next;
        }
        return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        // 找环相遇节点
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                //相遇点
                ListNode *meet = slow;
                //将meet->next保存到其他节点，在将meet->next设为空，以防找相交链表永远死循环
                ListNode *otherNode = meet->next;
                meet->next = nullptr;
                //头节点和meet的相交链表就是入环口
                return getIntersectionNode(head, otherNode);
            }
        }
        return nullptr;
    }
};


//思路2：
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast) {
            slow = slow->next;
            //fast->next == nullptr表示无环
            if (fast->next == NULL) {
                return NULL;
            }
            fast = fast->next->next;
            //相遇后,跟head一起走直到相等就是入环节点
            if (fast == slow) {
                ListNode *ptr = head;
                //两个指针相遇时，它们相遇的节点一定是环的入口节点
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return NULL;
    }
};
//https://leetcode.cn/problems/linked-list-cycle-ii/description/