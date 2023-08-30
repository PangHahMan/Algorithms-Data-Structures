/* 
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
2 - abc
3 - def
4 - ghi
5 - jkl
6 - mno
7 - pqrs
8 - tuv
9 - wxyz

示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 将对应的字符串保存在字符串数组中
    vector<string> _strToNum{"", "", "abc", "def", "ghi", "jki", "mno", "pqrs", "tuv", "wxyz"};

    void Combantions(string &digits, int di, string comstr, vector<string> &strV) {
        if (di == digits.size()) {
            strV.push_back(comstr);
            return;
        }
        // 思路:先走a b，每走一次，+=到comstr里，最后尾插到strV中，然后返回a 在走a e 返回a 在走a f 模拟这个过程
        // 将digits数字字符串转换成数字
        int num = digits[di] - '0';
        // num_str 就是数字对应的字符串
        string num_str = _strToNum[num];// abc

        for (int i = 0; i < num_str.size(); i++) {
            // 递归num_str 也就是a  b  c  这里需要画一个递归展开图,a递归过去，然后递归def,递归三次,返回回去 在b开始递归
            Combantions(digits, di + 1, comstr + num_str[i], strV);// comstr  a
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> strV;
        // 如果digits是个空串，直接返回strV
        if (digits == "")
            return strV;
        // digits是数字串，0是层数，""一开始是空串，strV是返回的vector<string>

        Combantions(digits, 0, "", strV);
    }
};