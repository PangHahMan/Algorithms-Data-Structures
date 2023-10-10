/* 
给定两个以字符串形式表示的非负整数num1和num2，返回num1和num2的乘积，它们的乘积也表示为字符串形式。
注意：不能使用任何内置的BigInteger库或直接将输入转换为整数。

示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"
*/
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        //其中一个为0，相乘就为0
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        //存放的字符串
        string ans = "0";
        //m和n为两个字符串的长度
        int m = num1.size(), n = num2.size();
        //遍历下面的字符串从最右边以此跟上面的字符串相乘 -> 乘法规则
        for (int i = n - 1; i >= 0; i--) {
            string curr;
            int add = 0;
            //初始化当前位置的值为0,在之后进行错位，用于后面相加,乘法每行得出的结果都是错位的
            for (int j = n - 1; j > i; j--) {
                curr.push_back(0);
            }
            //y转换成数字,num2的字符串
            int y = num2.at(i) - '0';
            //遍历上面的字符串依次跟y做乘法然后相加起来
            for (int j = m - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }

            //继续判断add的进位值如果不等于0 就要继续相加
            while (add != 0) {
                curr.push_back(add % 10);
                add /= 10;
            }
            //反转后，此时curr里面保存的就是第一行的结果
            reverse(curr.begin(), curr.end());
            //将curr的数字字符串转换成字符串
            for (auto &c: curr) {
                c += '0';
            }
            //字符串相加即可
            ans = addStrings(ans, curr);
        }
        return ans;
    }

    string addStrings(string &num1, string &num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }
};

//https://leetcode.cn/problems/multiply-strings/description/