//https://leetcode.cn/problems/implement-queue-using-stacks/
#include <stack>
using namespace std;
/* 使用两个栈，一个作为主栈，一个作为辅助栈。
元素入队时，直接将元素压入主栈。
元素出队时，先将主栈中的元素依次弹出并压入辅助栈，这样元素的顺序反转了。
弹出辅助栈的栈顶元素即为出队元素 */
class MyQueue {
public:
    stack<int> st1;// 主要栈，用于 push 操作和存储队列元素
    stack<int> st2;// 辅助栈，用于 pop 和 peek 操作时暂存元素

    MyQueue() {
    }

    // 将元素压入主栈 st1
    void push(int x) {
        st1.push(x);
    }

    // 执行出队操作，返回队首元素并将其从队列中移除
    int pop() {
        // 如果辅助栈 st2 为空，将主栈 st1 中的元素逐个移到 st2 中
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        // 弹出并返回 st2 的栈顶元素，实现出队操作
        int tmp = st2.top();
        st2.pop();
        return tmp;
    }

    // 返回队首元素但不移除
    int peek() {
        // 如果辅助栈 st2 为空，将主栈 st1 中的元素逐个移到 st2 中
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        // 返回 st2 的栈顶元素，实现 peek 操作
        return st2.top();
    }

    // 检查队列是否为空
    bool empty() {
        // 队列为空的条件是主栈和辅助栈都为空
        return st1.empty() && st2.empty();
    }
};
