/* 
描述
输入一个长度为 n 字符串，打印出该字符串中字符的所有排列，你可以以任意顺序返回这个字符串数组。
例如输入字符串ABC,则输出由字符A,B,C所能排列出来的所有字符串ABC,ACB,BAC,BCA,CBA和CAB。

示例1
输入："ab"
返回值：["ab","ba"]
说明：
返回["ba","ab"]也是正确的         

示例2
输入："aab"
返回值：["aab","aba","baa"]

示例3
输入："abc"
返回值：["abc","acb","bac","bca","cab","cba"]

示例4
输入：""
返回值：[""]
*/
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void helper(string &str, vector<string> &res, string &cur, vector<int> &visited) {
        // 如果当前排列结果的长度等于输入字符串的长度，说明已形成一个完整的排列，将其添加到结果集中
        if (cur.size() == str.size()) {
            res.push_back(cur);
            return;
        }
        // 遍历输入字符串的每个字符
        for (int i = 0; i < str.size(); i++) {
            // 如果当前字符已被访问过，跳过此次循环
            if (visited[i] == 1){
                continue;
            } 
            // 如果当前字符和前一个字符相同，并且前一个字符还未被访问过，跳过此次循环
            // 这是为了去除重复解
            if (i > 0 && str[i] == str[i - 1] && visited[i - 1] == 0){
                continue;
            } 
            visited[i] = 1;                // 标记当前字符已被访问
            cur.push_back(str[i]);         // 将当前字符添加到当前排列结果中
            helper(str, res, cur, visited);// 递归调用，进行下一层搜索
            cur.pop_back();                // 回溯，撤销上一步的选择
            visited[i] = 0;                // 回溯，标记当前字符未被访问
        }
    }

    vector<string> Permutation(string str) {
        // 如果输入字符串为空，直接返回空集 ? 
        if (str.empty()){
            return {};
        }

        vector<string> res;                // 用于存储所有排列结果的变量
        string cur;                        // 用于存储当前排列结果的变量
        vector<int> visited(str.size(), 0);// 用于记录每个字符是否已被访问的变量
        sort(str.begin(), str.end());      // 将输入字符串排序，为了去除重复解
        helper(str, res, cur, visited);    // 调用回溯搜索函数
        return res;                        // 返回所有排列结果
    }
};

//https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?
