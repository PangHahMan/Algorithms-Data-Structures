//https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
// 牛客这题的描述 小学生

//思路：这个题目首先需要明确矩阵是固定的，其次是矩阵相乘的方法
/* 
矩阵相乘 |a1 a2| * |c1 c2| = |a1c1 + a2d1 a1c2 + a2d2| |b1 b2| |d1 d2| |b1c1 + b2d1 b1d2 + b2d2|
矩阵是|1 1|^2 = |1 1|*|1 1|=|2 1| |1 0| |1 0| |1 0| |1 1| n的取值：1 2 3 4 5 6 .... 左上角值：1 2 3 5 8 13 .... 是一个变式的斐波那契 */
#include <iostream>
#include <vector>
using namespace std;
void data_init(vector<int> &v) {
    for (int i = 3; i < 10001; ++i) {
        v.push_back((v[i - 2] + v[i - 1]) % 10000);
    }
}

int main() {
    vector<int> v = {0, 1, 2};
    data_init(v);//初始化斐波那契数列
    int n, x;    //n表示输入的数，x才是表示n的值
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> x;
            printf("%04d", v[x]);
        }
        printf("\n");
    }
    return 0;
}
