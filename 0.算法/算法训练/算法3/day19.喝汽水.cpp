/* 描述
某商店规定：三个空汽水瓶可以换一瓶汽水，允许向老板借空汽水瓶（但是必须要归还）。
小张手上有n个空汽水瓶，她想知道自己最多可以喝到多少瓶汽水。 

输入描述：
输入文件最多包含 10 组测试数据，每个数据占一行，仅包含一个正整数 n（ 1<=n<=100 ），表示小张手上的空汽水瓶数。n=0 表示输入结束，你的程序不应当处理这一行。

输出描述：
对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。
输入：3
10
81
0

输出：
1
5
40

说明：
样例 1 解释：用三个空瓶换一瓶汽水，剩一个空瓶无法继续交换
样例 2 解释：用九个空瓶换三瓶汽水，剩四个空瓶再用三个空瓶换一瓶汽水，剩两个空瓶，向老板借一个空瓶再用三个空瓶换一瓶汽水喝完得一个空瓶还给老板    
*/

#include <iostream>
using namespace std;

int calNum(int n) {
    int sum = 0;
    while (n > 1) {
        int res = n / 3; //所能兑换的数
        int left = n % 3;//遗留的数
        sum += res;
        n = res + left;
        if (n == 2) {
            //n==2可以向老板借一瓶
            sum++;
            break;
        }
    }
    return sum;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        int res = calNum(n);
        cout << res << endl;
    }
    return 0;
}

//https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f?tpId=37&&tqId=21245&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking