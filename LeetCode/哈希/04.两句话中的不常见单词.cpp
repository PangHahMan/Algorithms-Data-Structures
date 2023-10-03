/* 
句子是一串由空格分隔的单词。每个单词仅由小写字母组成。
如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却没有出现 ，那么这个单词就是不常见的 。
给你两个句子s1和s2 ，返回所有不常用单词的列表。返回列表中单词可以按任意顺序组织。

示例 1：
输入：s1 = "this apple is sweet", s2 = "this apple is sour"
输出：["sweet","sour"]

示例 2：
输入：s1 = "apple apple", s2 = "banana"
输出：["banana"]
 */


#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/* 思路：通过题意可知，不常见单词即为出现次数为1次的单词，具体方法如下
 1. 将A和B两个字符串拼接，存于s中
 2. 从s中分离出单词，保存在vector vRet中
 3. 使用unordered_map统计vRet中每个单词出现的次数
 4. 遍历unordered_map，将出现一次的单词保存在vRet中
 5. 返回vRet
 */

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        //1.将A和B两个字符串拼接
        string s = s1 + " " + s2;

        vector<string> vRet;
        //2.从s中分离出单词，保存在vector vRet中
        for (int i = 0; i < s.size(); i++) {
            string ret;
            while (i < s.size() && s[i] != ' ') {
                ret += s[i];
                i++;
            }
            vRet.push_back(ret);
        }
        
        //3.使用unordered_map统计vRet中每个单词出现的次数
        unordered_map<string, int> mp;
        for (auto &s: vRet) {
            mp[s]++;
        }

        vRet.clear();
        
        //4.遍历unordered_map，将出现一次的单词保存在vRet中
        for (auto &m: mp) {
            if (m.second == 1) {
                vRet.push_back(m.first);
            }
        }

        return vRet;
    }
};

//https://leetcode.cn/problems/uncommon-words-from-two-sentences/