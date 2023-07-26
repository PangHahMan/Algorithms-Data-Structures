/* 
描述
根据输入的日期，计算是这一年的第几天。
保证年份为4位数且日期合法。

输入描述：
输入一行，每行空格分割，分别是年，月，日

输出描述：
输出是这一年的第几天

示例1
输入：2012 12 31
输出：366

示例2
输入：1982 3 4
输出：63 
*/

#include <iostream>
using namespace std;

//判断闰年
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//根据年和月获取月份的天数
int getDaysByYM(int year, int month) {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year)) {
        return 29;
    }
    return days[month];
}

//根据年月日获取相应的这一年的第几天
int getDaysByYMD(int year, int month, int day) {
    int days = 0;
    for (int i = 1; i < month; i++) {
        days += getDaysByYM(year, i);
    }
    return days + day;
}

int main() {
    int year, month, day;
    int days = 0;
    while (cin >> year >> month >> day) {
        days = getDaysByYMD(year, month, day);
        cout << days << endl;
    }
    return 0;
}

//https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking