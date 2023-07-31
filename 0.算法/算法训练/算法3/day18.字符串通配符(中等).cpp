/*思路： 
本题可以通过递归求解。从前向后一次匹配，遇到相同字符，都向后移动一个字符，如果通配符遇到"?"，则
不需匹配，自动跳过一个字符，如果通配符遇到"*"，则可以匹配任意多个字符，包括0个，此时可以有三种
选择，1，匹配0个，通配符向后移动一个字符，字符串不动。2，匹配1个，通配符和字符串都向后移动一个
字符。3，匹配多个，通配符不动，字符串向后移动一个字符。
递归的终止条件：通配符或者字符串遇到'\0'。当他们同时结束。 */

#include <iostream>
#include <string>
using namespace std;


bool strMatch(const char *pattern, const char *str) {
    //通配符串和匹配串都走到\0表示匹配
    if (*pattern == '\0' && *str == '\0') {
        return true;
    }
    //其中一个为\0，一个没走完，则不匹配
    if (*pattern == '\0' || *str == '\0') {
        return false;
    }
    //如果是? 匹配任意1个字符, 都往前+1
    if (*pattern == '?') {
        //题目强调?只能够匹配数字和字母，所以增加新的判断
        if (!isdigit(*str) && !isalpha(*str))
            return false;

        return strMatch(pattern + 1, str + 1);
    }
    //遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个字符)
    else if (*pattern == '*') {
        // 遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个字符)
        //这里需要处理连续的*号，否则会出现无限递归的问题
        //比如 **  连续两个*   碰到第一个* 匹配str
        while (*pattern == '*') {
            pattern++;
        }

        pattern--;
        if (!isdigit(*str) && !isalpha(*str)) {
            return strMatch(pattern + 1, str);
        }

        return strMatch(pattern + 1, str) || strMatch(pattern + 1, str + 1) || strMatch(pattern, str + 1);
    }
    //没有通配符，两个字符相等，则继续走
    else if (tolower(*pattern) == tolower(*str)) {
        return strMatch(pattern + 1, str + 1);
    }


    return false;
}

int main() {
    string pattern, str;
    while (cin >> pattern >> str) {
        bool ret = strMatch(pattern.c_str(), str.c_str());
        if (ret) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}

//https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036?tpId=37&&tqId=21294&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking