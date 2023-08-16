//https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c?

/* 
【解题思路】：
平均分三份是最快的方法，两份进行称重（对比出三个的重量 ），后对最重的那份再次进行称重，直到称重
的个数不足2个时则结束，获得假币 如果无法平均分3分则余数要么是1要么是2，因为是要最多称几次，n=n/3+1
满足每次取最大分称3份，取两份一样多的过秤，然后把三份中最多的那份继续分，直到硬币剩余0或1时截至
*/

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    while (cin >> n) {
        //硬币为0直接break;
        if (n == 0) {
            break;
        }
        int count = 0;  //计数器
        while (n > 1) {
            //判断是否可以整除，有余数的还要进行一次判断,所以要+1，让n>1,比如n=5
            if (n % 3) {
                n = n / 3 + 1;
            } else {
                n = n / 3;
            }
            count++;
        }
        cout << count << endl;
    }
    return 0;
}