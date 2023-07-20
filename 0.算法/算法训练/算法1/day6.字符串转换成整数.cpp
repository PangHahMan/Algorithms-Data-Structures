/* 描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为 0 或者字符串不是一个合法的数值则返回 0 

示例1
输入："+2147483647"
返回值：2147483647

示例2
输入："1a33"
返回值：0
*/


/* 解题思路非常简单，就是上次计算的结果*10，相当于10进制进位，然后加当前位的值。
例如：“123”转换的结果是
sum=0
sum*10+1->1
sum*10+2->12
sum*10+3->123
本题的关键是要处理几个关键边界条件：
1. 空字符串
2. 正负号处理
3. 数字串中存在非法字符
 */

#include <iostream>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        if (str.empty()) {
            return 0;
        }
        //定义flag，处理正负号
        int flag = 1;
        if (str[0] == '-') {
            flag = -1;
            str[0] = '0';
        } else if (str[0] == '+') {
            flag = 1;
            str[0] = '0';//为了处理第一个数既没有正号也不是负号，置为0不影响结果,注意这里是字符0,对应下面的if逻辑
        }

        long long sum = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                sum = sum * 10 + str[i] - '0';//str[i] - '0'  将字符串转换成数字
            } else {
                sum = 0;
                break;
            }
        }

        return sum * flag;
    }
};

//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking