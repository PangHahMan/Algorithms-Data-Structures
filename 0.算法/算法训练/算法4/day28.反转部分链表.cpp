//https://www.nowcoder.com/questionTerminal/f11155006f154419b0bef6de8918aea2?answerType=1&f=discussion

#include <iostream>
using namespace std;

struct ListNode {
    ListNode *next;
    int val;
};

// 输入链表节点的函数
ListNode *input_ListNode(int n) {
    int val;
    ListNode *head = nullptr;
    ListNode *cur = nullptr;
    
    for (int i = 0; i < n; i++) {
        cin >> val;
        ListNode *newNode = new ListNode();
        newNode->val = val;
        newNode->next = nullptr;
        
        if (head == nullptr) {
            head = newNode;
            cur = newNode;
        } else {
            cur->next = newNode;
            cur = newNode;
        }
    }
    return head;
}

// 反转链表的一部分
ListNode *reverse(ListNode *head, int L, int R) {
    // 创建一个虚拟头节点以处理边界情况
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *prevNode = dummy;

    // 找到需要反转部分的起始前一个节点
    for (int i = 0; i < L - 1; i++) {
        prevNode = prevNode->next;
    }

    ListNode* cur = prevNode->next;

    // 部分反转链表
    for (int i = 0; i < R - L; i++) {
        ListNode* nextNode = cur->next;
        cur->next = nextNode->next;
        nextNode->next = prevNode->next;
        prevNode->next = nextNode;
    }

    // 获取新的链表头节点
    ListNode* newHead = dummy->next;
    delete dummy;

    return newHead;
}

// 输出链表节点的函数
void out_put_List(ListNode* newHead) {
    while (newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    ListNode *grant = input_ListNode(n);
    int L, R;
    cin >> L >> R;
    
    // 反转链表的一部分
    ListNode *newHead = reverse(grant, L, R);
    
    // 输出反转后的链表
    out_put_List(newHead);

    // 清理内存，避免内存泄漏
    while (newHead) {
        ListNode *temp = newHead;
        newHead = newHead->next;
        delete temp;
    }
}


/* 思路：当理解和编写 reverse 函数时，我们需要考虑以下几个步骤，以及每个步骤的目的。这个函数的主要目标是在给定链表中反转从位置 L 到位置 R 的部分。下面是详细的步骤解释：
创建虚拟头节点 dummy：

为了处理L为1的情况，我们创建一个虚拟头节点 dummy，将其next 指向链表的真实头节点 head。这样，无论 L 是多少，我们都可以通过 dummy 来找到起始反转位置的前一个节点。
定位前一个节点 prevNode：

使用一个循环找到需要反转部分的起始前一个节点 prevNode。我们迭代 prevNode 直到它到达 L - 1 的位置，因为我们需要反转从位置 L 开始的部分。
初始化当前节点 cur：

我们用 cur 指针来追踪我们当前正在处理的节点，初始时它是 prevNode 的下一个节点。
部分链表反转循环：

使用循环，我们将 cur 的下一个节点逐个移到起始前一个节点 prevNode 的下一个，以实现反转。在每次循环迭代中，我们将 cur->next 节点移动到反转部分的前面，同时更新 cur->next，使其指向 nextNode->next，即当前节点的下一个节点。
更新节点指针关系：

在每次循环迭代中，我们通过更改指针关系，将 nextNode 插入到 prevNode 与 cur 之间，从而实现反转。
获取新的头节点：

反转部分完成后，我们用 dummy->next 来获取新的链表头节点，因为虚拟头节点 dummy 的 next 指向了反转后的链表部分的第一个节点。
释放虚拟头节点内存：

我们释放虚拟头节点 dummy 的内存，因为它在函数结束后不再需要。
返回新的头节点：

我们返回新的头节点作为反转后链表的起始节点。
通过这些步骤，reverse 函数成功地反转了链表中从位置 L 到位置 R 的部分。这个函数充分利用了指针操作来实现链表节点的移动和重新连接，从而在不创建新节点的情况下完成了反转操作。 */