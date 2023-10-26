/* 描述
求一个int类型数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
输入描述：
输入一个int类型数字

输出描述：
输出转成二进制之后连续1的个数

示例1
输入：200
输出：2
说明：200的二进制表示是11001000，最多有2个连续的1。   
*/
#include <iostream>
using namespace std;

int maxConsecutiveOnes(int num) {
    int max = 0;
    int count = 0;

    while (num > 0) {
        if (num & 1) {
            count++;
            if (count > max) {
                max = count;
            }
        } else {
            count = 0;
        }
        num >>= 1;
    }

    // for (int i = 0; i < 32; i++) {
    //     //num & (1 << i) 表达式的结果是0或者非零
    //     if ((num & (1 << i))) {
    //         count++;
    //         if (count > max) {
    //             max = count;
    //         }
    //     } else {
    //         count = 0;
    //     }
    // }
    return max;
}

int main() {
    int num;
    cin >> num;

    int result = maxConsecutiveOnes(num);
    cout << result << endl;

    return 0;
}

//https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2?tpId=37&&tqId=2130