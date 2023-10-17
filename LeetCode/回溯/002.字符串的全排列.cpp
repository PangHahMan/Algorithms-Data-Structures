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
#include <set>
#include <string>
#include <vector>
using namespace std;
//思路1
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
            if (visited[i] == 1) {
                continue;
            }
            // 如果当前字符和前一个字符相同，并且前一个字符还未被访问过，跳过此次循环
            // 这是为了去除重复解
            if (i > 0 && str[i] == str[i - 1] && visited[i - 1] == 0) {
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
        if (str.empty()) {
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


//思路2 ：交换
class Solution {
public:
    // 交换字符串中的两个字符
    void swap(string &str, int i, int j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // 递归生成所有排列
    void _Permutation(string &str, int start, set<string> &result) {
        // 当start达到字符串的最后位置，我们找到了一个新的排列，插入到结果集合中
        if (start == str.size() - 1) {
            result.insert(str);
            return;
        }

        // 将start位置的字符与后面的每一个字符交换，并递归生成排列
        for (int i = start; i < str.size(); i++) {
            /* 
            1.首先，swap(str, start, i)将起始位置的字符（即第start个字符）与后面的字符（即第i个字符）进行交换，这样就在字符串的起始位置得到一个新的字符，也就得到了字符串的一个新的排列。
            2.然后，调用_Permutation(str, start + 1, result)进行递归，生成以这个新的字符开头的所有排列。注意这里的递归是在start + 1位置开始的，也就是说，固定了前start个字符，然后对剩余的字符进行全排列。
            3.最后，swap(str, start, i)将字符换回来，也就是恢复了原来的字符串。这是因为在递归调用结束后，我们需要恢复原来的字符串，以确保在下一次循环中，当i增加时，我们仍然是在原来的字符串上进行操作，而不是在已经被修改过的字符串上进行操作。这种技术称为“回溯”。
             */
            swap(str, start, i);                 // 交换字符
            _Permutation(str, start + 1, result);// 递归生成排列
            swap(str, start, i);                 // 回溯，恢复原字符串
        }
    }

    // 主函数，生成字符串的所有排列
    vector<string> Permutation(string str) {
        // 使用set存储结果，自动去重并排序
        set<string> result_set;
        if (str.empty()) {
            return {};
        }

        // 从第一个字符开始生成排列
        _Permutation(str, 0, result_set);

        // 将set转为vector并返回
        vector<string> result(result_set.begin(), result_set.end());

        return result;
    }
};


//https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?
