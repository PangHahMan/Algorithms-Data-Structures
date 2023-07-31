/* 描述
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
注：子串的定义：将一个字符串删去前缀和后缀（也可以不删）形成的字符串。请和“子序列”的概念分开！

输入描述：
输入两个字符串

输出描述：
返回重复出现的字符

示例1
输入：
abcdefghijklmnop
abcsafjklmnopqrstuvw
输出：jklmnop 
*/


/* 本题需要用动态规划求解，MCS[i][j]记录短字符串s1前i个字符和长字符串s2前j个字符的最长子串的长度，初始化所有值为0。
当s1[i-1] = s2[j-1]时，MCS[i][j] = MCS[i - 1][j - 1] + 1，这里使用一个额外的值start来记录最长子串在短字符串s1中出现的起始位置maxlen记录当前最长子串的长度，当MCS[i][j] >maxlen 时，maxlen = MCS[i][j]， 则start = i - maxlen ；
当s1[i-1] != s2[j-1]时不需要任何操作，最后获取substr(start, maxlen)即为所求。 

//设计一个矩阵
    a b c d e f g g u j
    0 1 2 3 4 5 6 7 8 9 
a 0  
b 1   1
c 2     2
d 3       3
e 4
f 5
g 6
h 7


*/

#include <iostream>
#include <vector>
using namespace std;

string get_Max_sizeStr(string &str1, string &str2) {

    //让str1为最短子串
    if (str1.size() > str2.size()) {
        swap(str1, str2);
    }

    int len1 = str1.size();
    int len2 = str2.size();
    vector<vector<int>> MSC(len1 + 1, vector<int>(len2 + 1, 0));
    int start = 0, max_size = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                MSC[i][j] = MSC[i - 1][j - 1] + 1;
            }

            if (MSC[i][j] > max_size) {
                max_size = MSC[i][j];
                start = i - max_size;
            }
        }
    }
    return str1.substr(start, max_size);
}


int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        string ret = get_Max_sizeStr(str1, str2);
    }
}