/* 描述
设计一个程序能计算一个日期加上若干天后是什么日期。

输入描述：
输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。

输出描述：
输出m行，每行按yyyy-mm-dd的个数输出。

输入：
1
2008 2 3 100

输出：
2008-05-13
*/

#include <iostream>
using namespace std;

bool is_leap_year(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int month_day(int year, int month) {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days[month];
}

void Getdays(int &year, int &month, int &day, int days) {
    day += days;
    //当day不大于当前月份的天数说明day合法了
    while (day > month_day(year, month)) {
        day -= month_day(year, month);
        month++;
        //如果month>12，更新month和year
        if (month > 12) {
            year++;
            month = 1;
        }
    }
}

int main() {
    int m = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int year, month, day, days;
        cin >> year >> month >> day >> days;
        Getdays(year, month, day, days);
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}