/* 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
实现 MyStack 类：
void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
*/
#include<queue>
#include<algorithm>
using namespace std;
class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;

    MyStack() {
    }
    
    //利用两个队列,先push到队列2中,在将队列1中的所有数据push到队列2中,然后在进行交换。 
    void push(int x) {
        queue2.push(x);
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        swap(queue1, queue2);
    }

    int pop() {
        int r = queue1.front();
        queue1.pop();
        return r;
    }

    int top() {
        int r = queue1.front();
        return r;
    }

    bool empty() {
        return queue1.empty();
    }
};

//leetcode.cn/problems/implement-stack-using-queues/solutions/432204/yong-dui-lie-shi-xian-zhan-by-leetcode-solution/
  