/* 
给你一个字符串数组 tokens ，表示一个根据逆波兰表示法表示的算术表达式。
请你计算该表达式。返回一个表示表达式值的整数。

示例 1：
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9

示例 2：
输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6

示例 3：
输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。
平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
*/

#include <functional>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<long> st;// 创建一个用于存放操作数的栈
        // 定义一个映射，将操作符映射到对应的函数
        unordered_map<string, function<long(long, long)>> opFuncMap = {
                {"+", [](long i, long j) { return i + j; }},
                {"-", [](long i, long j) { return i - j; }},
                {"*", [](long i, long j) { return i * j; }},
                {"/", [](long i, long j) { return i / j; }}};

        // 遍历输入的逆波兰表达式
        for (auto &str: tokens) {
            if (opFuncMap.find(str) != opFuncMap.end()) {// 如果当前元素是操作符
                long right = st.top();                   // 弹出栈顶的右操作数
                st.pop();
                long left = st.top();// 弹出栈顶的左操作数
                st.pop();

                // 根据操作符在映射中找到对应的函数，并将计算结果压入栈
                st.push(opFuncMap[str](left, right));
            } else {                // 如果当前元素是操作数
                st.push(stoll(str));// 将操作数转换为长整型并压入栈
            }
        }
        return st.top();// 返回栈顶元素，即最终的计算结果
    }
};

//https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/