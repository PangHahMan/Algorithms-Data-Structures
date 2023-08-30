/* 描述
给出年分m和一年中的第n天，算出第n天是几月几号。

输入：
2000 3
2000 31
2000 40
2000 60
2000 61
2001 60

输出：
2000-01-03
2000-01-31
2000-02-09
2000-02-29
2000-03-01
2001-03-01
 */


#include <iostream>
using namespace std;

// 定义每个月的天数，其中索引0不使用
int day_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 判断是否为闰年的函数
bool is_leap_year(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int main() {
    int year, day_of_year;
    // 持续读取输入直到无法继续
    while (cin >> year >> day_of_year) {
        // 判断是否为闰年，从而决定2月的天数
        if (is_leap_year(year)) {
            day_in_month[2] = 29;
        } else {
            day_in_month[2] = 28;
        }

        int month = 1;
        int sum = 0;
        sum += day_in_month[1];
        // 计算月份
        while (day_of_year > sum) {
            month++;
            sum += day_in_month[month];
        }

        //计算day,day是总天数减去sum的值减去最后加的月份天数 比如总天数44 而sum = 1月+2月 = 59 那么day就应该是44 - 31，44就是day_of_year,而31是sum-最后+的月份59-28=31
        int day = day_of_year - (sum - day_in_month[month]);
        // 输出格式化的日期
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}
