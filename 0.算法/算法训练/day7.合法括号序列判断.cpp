/* 描述
给定一个字符串A和其长度n，请返回一个bool值代表它是否为一个合法的括号串（只能由括号组成）。

测试样例：
"(()())",6
返回：true

测试样例：
"()a()()",7
返回：false

测试样例：
"()(()()",7
返回：false 
*/

/* 用栈结构实现，栈中存放左括号，当遇到右括号之后，检查栈中是否有左括号，如果有则出栈，如果没有，
则说明不匹配。 */

#include <stack>
#include <string>
using namespace std;
class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (A[i] == '(') {
                st.push(A[i]);
            } else if (A[i] == ')') {
                //如果栈中为空,或者不为(则不匹配
                if (st.empty() || st.top() != '(') {
                    return false;
                } else {
                    //相等则pop即可
                    st.pop();
                }
            }
        }
        //可能出现左括号比右括号多,此时不匹配,但栈中还有很多左括号,需要判断
        if (st.empty()) {
            return true;
        }
        return false;
    }
};

//https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking