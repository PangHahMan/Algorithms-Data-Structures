/* 
给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。

示例 1：
输入: s = "leetcode"
输出: 0

示例 2:
输入: s = "loveleetcode"
输出: 2

示例 3:
输入: s = "aabb"
输出: -1
*/
#include <string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        //分别对字符串进行正序查询和反序查询
        //如果所查询的字符下标相等，说明此字符只出现了一次
        for (int i = 0; i < s.size(); i++) {
            int index = s.find(s[i]);
            int reverse_index = s.rfind(s[i]);
            if (index == reverse_index)
                return i;
        }
        return -1;
    }
};

//https://leetcode.cn/problems/first-unique-character-in-a-string/submissions/420501839/