/* 描述
有一种兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子。
例子：假设一只兔子第3个月出生，那么它第5个月开始会每个月生一只兔子。
一月的时候有一只兔子，假如兔子都不死，问第n个月的兔子总数为多少？

输入描述：
输入一个int型整数表示第n个月

输出描述：
输出对应的兔子总数 
*/

/* 
第n个月的兔子数量由两部分组成，一部分是上个月的兔子f(n-1)，另一部是满足3个月大的兔子，会生一只兔
子f(n-2)。所以第n个月兔子总数： f(n) = f(n - 1) + f(n - 2)。本题是在变相考察斐波那契数列。
*/

#include <iostream>
using namespace std;
int Fib(int n) {
    if (n <= 2)
        return 1;
    else
        return Fib(n - 1) + Fib(n - 2);
}

int main() {
    int month;
    int sum = 0;
    while (cin >> month) {
        sum = Fib(month);
        cout << sum << endl;
    }
    return 0;
}

//https://www.nowcoder.com/practice/1221ec77125d4370833fd3ad5ba72395?tpId=37&&tqId=21260&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking