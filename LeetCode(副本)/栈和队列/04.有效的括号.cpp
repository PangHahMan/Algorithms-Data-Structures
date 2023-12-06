/* 
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false
*/

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

//https://leetcode.cn/problems/valid-parentheses/description/