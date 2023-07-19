/* 描述
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
输入描述：
输入两个正整数A和B。

输出描述：
输出A和B的最小公倍数。

示例1
输入：5 7
输出：35

示例2
输入：2 4
输出：4 
*/

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int max = a > b ? a : b;
    while (max) {
        if (max % a == 0 && max % b == 0) {
            break;
        }
        max++;
    }
    cout << max << endl;

    return 0;
}


//https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&&tqId=21331&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking