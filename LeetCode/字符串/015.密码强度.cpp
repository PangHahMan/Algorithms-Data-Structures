/* 描述
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。 
一、密码长度:
5 分: 小于等于4 个字符
10 分: 5 到7 字符
25 分: 大于等于8 个字符

二、字母:
0 分: 没有字母
10 分: 密码里的字母全都是小（大）写字母
20 分: 密码里的字母符合”大小写混合“

三、数字:
0 分: 没有数字
10 分: 1 个数字
20 分: 大于1 个数字

四、符号:
0 分: 没有符号
10 分: 1 个符号
25 分: 大于1 个符号

五、奖励（只能选符合最多的那一种奖励）:
2 分: 字母和数字
3 分: 字母、数字和符号
5 分: 大小写字母、数字和符号

最后的评分标准:
>= 90: 非常安全
>= 80: 安全（Secure）
>= 70: 非常强
>= 60: 强（Strong）
>= 50: 一般（Average）
>= 25: 弱（Weak）
>= 0:  非常弱（Very_Weak）

对应输出为：

VERY_SECURE
SECURE
VERY_STRONG
STRONG
AVERAGE
WEAK
VERY_WEAK

请根据输入的密码字符串，进行安全评定。

注：
字母：a-z, A-Z
数字：0-9
符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
!"#$%&'()*+,-./     (ASCII码：0x21~0x2F)
:;<=>?@             (ASCII码：0x3A~0x40)
[\]^_`              (ASCII码：0x5B~0x60)
{|}~                (ASCII码：0x7B~0x7E)

提示:
1 <= 字符串的长度<= 300
输入描述：
输入一个string的密码

输出描述：
输出密码等级

示例1
输入：38$@NoNoN
输出：VERY_SECURE
说明：样例的密码长度大于等于8个字符，得25分；大小写字母都有所以得20分；有两个数字，所以得20分；包含大于1符号，所以得25分；由于该密码包含大小写字母、数字和符号，所以奖励部分得5分，经统计得该密码的密码强度为25+20+20+25+5=95分。
         
示例2
输入：Jl)M:+
输出：AVERAGE

说明：示例2的密码强度为10+20+0+25+0=55分。
*/


#include <iostream>
#include <string>
using namespace std;

int getScore(string &str) {
    int digit = 0, symbol = 0;
    int lower = 0, upper = 0, charc = 0;
    int size = 0, sum = 0;
    for (auto ch: str) {
        if (ch >= 'a' && ch <= 'z') {
            lower++;
            charc++;
        } else if (ch >= 'A' && ch <= 'Z') {
            upper++;
            charc++;
        } else if (ch >= '0' && ch <= '9') {
            digit++;
        } else if ((ch >= 0x21 && ch <= 0x2F) ||
                   (ch >= 0x3A && ch <= 0x40) ||
                   (ch >= 0x5B && ch <= 0x60) ||
                   (ch >= 0x7B && ch <= 0x7E)) {
            symbol++;
        }
    }

    size = str.size();

    if (size <= 4)
        sum += 5;
    else if (size <= 7)
        sum += 10;
    else
        sum += 25;

    if (lower > 0 && upper > 0)
        sum += 20;
    else if (lower == charc || upper == charc)
        sum += 10;

    if (digit == 1)
        sum += 10;
    else if (digit > 1)
        sum += 20;

    if (symbol == 1)
        sum += 10;
    else if (symbol > 1)
        sum += 25;

    if (lower > 0 && upper > 0 && digit > 0 && symbol > 0)
        sum += 5;
    else if ((lower > 0 || upper > 0) && digit > 0 && symbol > 0)
        sum += 3;
    else if ((lower > 0 || upper > 0) && digit > 0 && symbol == 0)
        sum += 2;

    return sum;
}


int main() {
    string str;
    while (cin >> str) {
        int score = getScore(str);

        if (score >= 90) {
            cout << "VERY_SECURE" << endl;
        } else if (score >= 80) {
            cout << "SECURE" << endl;
        } else if (score >= 70) {
            cout << "VERY_STRONG" << endl;
        } else if (score >= 60) {
            cout << "STRONG" << endl;
        } else if (score >= 50) {
            cout << "AVERAGE" << endl;
        } else if (score >= 25) {
            cout << "WEAK" << endl;
        } else {
            cout << "VERY_WEAK" << endl;
        }
    }
    return 0;
}

//https://www.nowcoder.com/practice/52d382c2a7164767bca2064c1c9d5361?tpId=37&&tqId=21