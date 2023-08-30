#include <iostream>
using namespace std;

//使用C++面向对象和函数调用方式
class Date {
public:
    Date(int year, int month, int day) {
        _year = year;
        _month = month;
        _day = day;
    }

    static bool isLeap(int year) {
        if (((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)) {
            return true;
        }
        return false;
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
    int getDaysByYMD() {
        int days = 0;
        for (int i = 1; i < _month; i++) {
            days += getDaysByYM(_year, i);
        }
        return days + _day;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    int year = 0, month = 0, day = 0;
    cin >> year >> month >> day;
    Date d(year, month, day);
    int ret = d.getDaysByYMD();
    cout << ret << endl;
    return 0;
}