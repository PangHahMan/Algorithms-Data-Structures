/*
思路：
1. 提取所有的奇数位，如果该位是1，输出1，是0则输出0
2. 以同样的方式提取偶数位置

检测num中某一位是0还是1的方式：
   1. 将num向右移动i位
   2. 将移完位之后的结果与1按位与，如果：
      结果是0，则第i个比特位是0
      结果是非0，则第i个比特位是1
*/
#include <iostream>
using namespace std;
void Printbit(int num) {
    for (int i = 31; i >= 1; i -= 2) {
        cout << ((num >> i) & 1);
    }
    cout << endl;

    for (int i = 30; i >= 0; i -= 2) {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}