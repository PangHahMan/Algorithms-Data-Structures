/* 描述
Levenshtein距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。编辑距离的算法是首先由俄国科学家 Levenshtein 提出的，故又叫 Levenshtein Distance 。

例如：
字符串A: abcdefg
字符串B: abcdef

通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。
要求：
给定任意两个字符串，写出一个算法计算它们的编辑距离。

输入描述：
每组用例一共2行，为输入的两个字符串

输出描述：
每组用例输出一行，代表字符串的距离

示例1
输入：
abcdefg
abcdef

输出：
1 
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int minDistance(const string &str1, const string &str2) {
    // word与空串之间的编辑距离为word的长度
    if (str1.empty() || str2.empty()) {
        return max(str1.size(), str2.size());
    }
    int len1 = str1.size();
    int len2 = str2.size();
    //初始化二维矩阵
    vector<vector<int>> f(len1 + 1, vector<int>(len2 + 1, 0));
    //初始化行距离
    for (int i = 0; i <= len1; i++) {
        f[i][0] = i;
    }
    //初始化列距离
    for (int j = 0; j <= len2; j++) {
        f[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            // 动态规划 F(i,j) = min { F(i-1,j)+1, F(i,j-1) +1, F(i-1,j-1) + (w1[i]==w2[j]?0:1) }
            // 找出上面左边和左上角最小的值
            // 判断str1的第i个字符是否与str2的第j个字符相等
            if (str1[i - 1] == str2[j - 1]) {
                //先找出位置的上面和左边的最小值，在+1
                f[i][j] = min(f[i - 1][j], f[i][j - 1]);
                //当前位置在和左上角比较，由于字符相同，所以距离不发生变化
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            } else {
                //先找出位置的上面和左边的最小值，在+1
                f[i][j] = 1 + min(f[i - 1][j], f[i][j - 1]);
                //画图分析的时候，就假如一开始就不同,此时的值应该为1
                //当前位置和左上角比较,由于字符不同,所以距离需要变化,需要+1
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }
    return f[len1][len2];
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        cout << minDistance(str1, str2) << endl;
    }
    return 0;
}

//https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&&tqId=21275&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking