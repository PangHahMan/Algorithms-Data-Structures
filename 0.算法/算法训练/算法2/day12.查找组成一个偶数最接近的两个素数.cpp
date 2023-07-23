/* 描述
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对。 
输入描述：
输入一个大于2的偶数

输出描述：
从小到大输出两个素数

示例1
输入：20
输出：
7
13

示例2
输入：4
输出：
2
2
*/


/* 本题首先需要判断素数，素数表示除过1和本身，不能被其它数整除。通过循环遍历来判断一个数是否为素
数。最近的两个素数应该从最中间的位置开始向两边查找
 */
#include <cmath>
#include <iostream>
using namespace std;

bool is_prime(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i = n / 2; i >= 0; i--) {
        if (is_prime(i) && is_prime(n - i)) {
            cout << i << endl;
            cout << n - i << endl;
            break;
        }
    }
    return 0;
}