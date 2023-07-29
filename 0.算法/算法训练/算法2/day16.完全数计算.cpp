/* 描述
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。

它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。

例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
输入描述：
输入一个数字n

输出描述：
输出不超过n的完全数的个数

示例1
输入：1000

输出：3
*/

#include <iostream>
using namespace std;

int Get_Perfect_Num_Count(int n) {
    //1不是完全数
    int sum = 0, count = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {//除去本身相加j<i 而不是j<=i
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum == i) {//相等则是完全数
            count++;
        }
        sum = 0;
    }
    return count;
}

int main() {
    int n;
    while (cin >> n) {
        int count = Get_Perfect_Num_Count(n);
        cout << count << endl;
    }
    return 0;
}

//https://www.nowcoder.com/practice/7299c12e6abb437c87ad3e712383ff84?tpId=37&&tqId=212