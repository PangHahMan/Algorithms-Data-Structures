/* 描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表 1->2->3->3->4->4->5  处理后为 1->2->5 

示例1
输入：{1,2,3,3,4,4,5}
返回值：{1,2,5}

示例2
输入：{1,1,1,8}
返回值：{8}
*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

//思路:新建一个链表尾插到新链表中
class Solution {
public:
    ListNode *deleteDuplication(ListNode *pHead) {
        if (pHead == nullptr || pHead->next == nullptr) {
            return pHead;
        }

        ListNode *newHead = new ListNode(0);
        ListNode *cur = newHead;
        ListNode *prev = pHead;
        ListNode *last = prev->next;

        while (last) {
            if (prev->val != last->val) {
                cur->next = prev;
                cur = cur->next;
                prev = last;

            } else {
                while (last != nullptr && prev->val == last->val) {
                    last = last->next;
                }
                //这里设计的很巧妙,一直在更新cur->next 直到有一个不重复的。
                //这里没有更新cur,所以如果有一直连续的重复也不会有问题，重复插入,到最后插入一个nullptr
                cur->next = last;
                prev = last;  //跳过重复的数组
            }

            //防止空指针解引用
            if (last) {
                last = last->next;
            }
        }

        ListNode *result = newHead->next;
        delete newHead;
        return result;
    }
};