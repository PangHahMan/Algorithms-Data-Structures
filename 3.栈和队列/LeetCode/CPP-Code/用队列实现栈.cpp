//https://leetcode.cn/problems/implement-stack-using-queues/description/

/* 思路：
使用两个队列，始终保持一个队列为空。当我们需要进行压栈操作时，将数据压入不为空的队列中（若两个都为空，则随便压入一个队列）。当需要进行出栈操作时，将不为空的队列中的数据导入空队列，仅留下一个数据，这时将这个数据返回并且删除即可。判断栈是否为空，即判断两个队列是否同时为空。
 */
#include <queue>
using namespace std;
class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;

    MyStack() {
    }

    //数据压入不为空的队列
    void push(int x) {
        if (!queue1.empty()) {
            queue1.push(x);
        } else {
            queue2.push(x);
        }
    }

    //非空的队列数据从队头开始压入到空队列，剩下一个就是栈的pop元素
    int pop() {
        //先假设在修改
        queue<int> *emptyQueue = &queue1;
        queue<int> *noemptyQueue = &queue2;
        if (!emptyQueue->empty()) {
            emptyQueue = &queue2;
            noemptyQueue = &queue1;
        }

        // 非空队列的前n-1个数据倒入空队列
        while (noemptyQueue->size() > 1) {
            emptyQueue->push(noemptyQueue->front());
            noemptyQueue->pop();
        }

        // 取栈顶，也就是剩下的非空队列的最后一个数据，取完pop一下
        int top = noemptyQueue->front();
        noemptyQueue->pop();
        return top;
    }

    //思路；返回非空队列的队尾，即是栈顶
    int top() {
        if (!queue1.empty()) {
            return queue1.back();
        } else {
            return queue2.back();
        }
    }

    bool empty() {
        return queue1.empty() && queue2.empty();
    }
};