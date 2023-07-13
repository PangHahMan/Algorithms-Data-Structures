/* 描述
给定一个单链表的头结点pHead(该头节点是有值的，比如在下图，它的val是1)，长度为n，反转该链表后，返回新链表的表头。 

示例1
输入：{1,2,3}
返回值：{3,2,1}

示例2
输入：{}
返回值：{}
说明：空链表则输出空  
*/


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//思路1：定义三个指针，整体右移，边移动，边翻转，保证不会断链。
class Solution {
public:
    ListNode *ReverseList(ListNode *head) {
        //头指针为nullptr,或者下一个为nullptr,反转不变
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        //不带头结点，至少有2个节点

        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *third = second->next;//指向第三个节点，可能为nullptr

        while (third) {
            second->next = first;

            //指针整体后移
            first = second;
            second = third;
            third = third->next;
        }
        //最后一个节点头插third走到了nullptr,最后一个节点为second
        second->next = first;
        //将原来的初始位置的下一个置nullptr,否则打印无限循环
        head->next = nullptr;
        head = second;
        return head;
    }
};


//思路2：头插思想进行翻转
class Solution {
public:
    ListNode *ReverseList(ListNode *head) {
        //头指针为nullptr,或者下一个为nullptr,反转不变
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *cur = head;
        ListNode *newHead = nullptr;
        while (cur) {
            //保存下一个节点
            ListNode *next = cur->next;
            //头插到新节点
            cur->next = newHead;
            //新节点指向cur
            newHead = cur;
            cur = next;
        }

        return newHead;
    }
};