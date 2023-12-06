/* 
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
实现 MinStack 类:
MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
 */

#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

/* 
*思路：
1. 利用两个栈，一个为正常栈(保存所有的进出栈数据)，一个为最小栈(也一直入栈，一直入最小值,方便后续pop)
*/
class MinStack {
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int val) {
        x_stack.push(val);
        min_stack.push(min(min_stack.top(), val));//跟着x_stack一起入栈,保持两个栈数据一致
    }

    void pop() {
        x_stack.pop();
        min_stack.pop();
    }

    int top() {
        return x_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }

private:
    stack<int> x_stack;
    stack<int> min_stack;
};

//https://leetcode.cn/problems/min-stack/submissions/460540348/