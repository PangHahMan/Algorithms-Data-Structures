/* 描述
给定两个只包含小写字母的字符串，计算两个字符串的最大公共子串的长度。

注：子串的定义指一个字符串删掉其部分前缀和后缀（也可以不删）后形成的字符串。 

输入描述：
输入两个只包含小写字母的字符串

输出描述：
输出一个整数，代表最大公共子串的长度

示例1
输入：
asdfas
werasdfaswer

输出：6
*/

//这道题跟day19的几乎一模一样
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getMaxComSubstr(string &s1, string &s2) {
    int len1 = s1.size();
    int len2 = s2.size();

    vector<vector<int>> MSC(len1 + 1, vector<int>(len2 + 1, 0));
    int max_len = 0;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                MSC[i][j] = MSC[i - 1][j - 1] + 1;
            }

            if (MSC[i][j] > max_len) {
                max_len = MSC[i][j];
            }
        }
    }
    return max_len;
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        int max_len = getMaxComSubstr(s1, s2);
        cout << max_len << endl;
    }
    return 0;
}

//https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&&tqId=21298&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking