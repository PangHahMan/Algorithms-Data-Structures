/* 描述
输入两个整数，求两个整数二进制格式有多少个位不同

输入描述：两个整数
输出描述：二进制不同位的个数

示例1
输入：22 33
输出：5
*/

#include <iostream>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {// 注意 while 处理多个 case
        int tmp = a ^ b;
        int count = 0;
        while (tmp) {
            tmp = tmp & (tmp - 1);
            count++;
        }
        cout << count << endl;
    }
}

//https://www.nowcoder.com/practice/16e48900851646c0b2c6cdef9d7ea051?tpId=182&tqId=34802&ru=/exam/oj