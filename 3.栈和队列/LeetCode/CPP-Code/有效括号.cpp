//https://leetcode.cn/problems/valid-parentheses/
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                // 如果是左括号就入栈
                st.push(s[i]);
            } else {
                // 如果栈中没有数据，第一个就是右括号，说明不匹配
                if (st.empty()) {
                    return false;
                }
                // 取栈顶给top，作比较
                char top = st.top();

                if (top == '(' && s[i] == ')' ||
                    top == '{' && s[i] == '}' ||
                    top == '[' && s[i] == ']') {
                    // 匹配成功可以Pop了
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        //判断栈是否为空 如果匹配的话，所有的栈中数据都被Pop出来，则为空
        bool ret = st.empty();
        return ret;
    }
};
