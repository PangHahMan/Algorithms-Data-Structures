/* 
链接：https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
一个正整数可以分解成一个或多个数组的积。例如36=2*2*3*3，即包含2和3两个因子。NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数。 

输入
30 26 20
输出
3 2 2
*/

//30 = 2 3 5
//26 = 2 7
/* 
从最小因子2到数字的最大因子数（数字的平方根）开始判断是否能够取余
可以则循环取余直到取余不为0，因子个数+1；否则使用下一个因子计算；
最终整除了各个因子数之后剩余的数字不为1则本身也是一个因子，因此因子数+1
 */


#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int n = 0;
    while (cin >> n) {
        int k = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    n /= i;//26/2=13  13/2!=0  n最后等于13
                }
                k++;
            }
        }
        if (n != 1) {
            k++;
        }
        cout << k << endl;
    }

    return 0;
}