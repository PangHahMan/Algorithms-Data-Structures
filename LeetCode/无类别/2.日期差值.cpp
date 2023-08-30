#include <cmath>
#include <iostream>

class DateCalculator {
private:
    int mon[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

public:
    // 静态方法用于判断是否为闰年
    static bool isLeap(int year) {
        if (((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)) {
            return true;// 是闰年则返回 true
        }
        return false;// 不是闰年则返回 false
    }

    // 计算距离公元元年的总天数
    int CountDay(int y, int m, int d) {
        int yearDay = y * 365 + y / 4 - y / 100 + y / 400;
        int monthDay = mon[m - 1];// 获取截止到前一个月的天数
        if (m > 2 && isLeap(y))
            monthDay += 1;            // 如果是闰年且月份大于2，则需要加上闰日
        return yearDay + monthDay + d;// 总天数 = 年天数 + 月天数 + 当月天数
    }

    // 计算两个日期之间的天数差
    int calculateDateDifference(int year1, int month1, int day1, int year2, int month2, int day2) {
        int n1 = CountDay(year1, month1, day1);// 第一个日期的总天数
        int n2 = CountDay(year2, month2, day2);// 第二个日期的总天数
        return std::abs(n1 - n2) + 1;          // 返回两个日期之间的天数差，加1是因为要包括开始和结束日期
    }
};

int main() {
    DateCalculator calculator;
    int year1, month1, day1;
    std::scanf("%4d%2d%2d", &year1, &month1, &day1);

    int year2, month2, day2;
    std::scanf("%4d%2d%2d", &year2, &month2, &day2);

    int difference = calculator.calculateDateDifference(year1, month1, day1, year2, month2, day2);
    std::cout << difference << std::endl;

    return 0;
}
