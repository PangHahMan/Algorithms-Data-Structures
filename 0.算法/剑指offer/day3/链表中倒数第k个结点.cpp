/* 描述
输入一个链表，输出该链表中倒数第k个结点。 

示例1
输入：1,{1,2,3,4,5}
返回值：{5}
*/

/* 较优解题思路：
1. 题目中的链表是单链表，也就不能从后往前进行
2. 可以定义两个指针，一个指针先走k步，再让另一个指针跟在后面，使用“前后指针”的方式，当前面的指针到达结尾，后面的指针，也就是倒数第k个节点 
*/
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        if (pListHead == nullptr || k == 0) {
            return nullptr;
        }

        ListNode *front = pListHead;  //前面的节点
        ListNode *rear = pListHead;   //后面的节点

        //如果k的值大于front所有的节点呢？
        while (k > 0 && front) {
            front = front->next;
            k--;
        }

        if (k > 0) {
            return nullptr;
        }

        while (front) {
            front = front->next;
            rear = rear->next;
        }

        return rear;
    }
};

//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?