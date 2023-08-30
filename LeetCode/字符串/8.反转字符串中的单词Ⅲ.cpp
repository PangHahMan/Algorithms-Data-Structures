/* 
给定一个字符串s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1：
输入：s = "Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"

示例 2:
输入： s = "God Ding"
输出："doG gniD"
*/

#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size(); i++) {
            int index = i;
            //找到空字符串下标
            while (index < s.size() && s[index] != ' ') {
                index++;
            }
            //反转
            reverse(s.begin() + i, s.begin() + index);
            //更新i下标，防止重复反转
            i = index;
        }

        return s;
    }
};

//https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/