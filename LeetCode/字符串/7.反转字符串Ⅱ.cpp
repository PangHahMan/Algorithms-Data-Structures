/* 
给定一个字符串s和一个整数k，从字符串开头算起，每计数至2k个字符，就反转这2k字符中的前k个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例 1：
输入：s = "abcdefg", k = 2
输出："bacdfeg"

示例 2：
输入：s = "abcd", k = 2
输出："bacd"
*/

#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {

        for (int i = 0; i < s.size(); i += 2 * k) {
            //注意min函数的两边接收的类型要一致，s.size()的返回值是size_t 要强转成int
            reverse(s.begin() + i, s.begin() + min(i + k, (int) s.size()));
        }
        return s;
    }
};

//https://leetcode.cn/problems/reverse-string-ii/