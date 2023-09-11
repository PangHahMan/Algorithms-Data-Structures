/* 
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个回文串 。
字母和数字都属于字母数字字符。
给你一个字符串s，如果它是回文串 ，返回true ；否则，返回false 。

示例 1：
输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。

示例 2：
输入：s = "race a car"
输出：false
解释："raceacar" 不是回文串。

示例 3：
输入：s = " "
输出：true
解释：在移除非字母数字字符之后，s是一个空字符串 "" 。
由于空字符串正着反着读都一样，所以是回文串。 
*/

#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;//定义一个sgood用来存放被移除非小写字母和数字的字符串
        //转化字符串为小写
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }

        int left = 0, right = sgood.size() - 1;
        while (left < right) {
            if (sgood[left] != sgood[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

//https://leetcode.cn/problems/valid-palindrome/submissions/
