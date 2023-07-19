/* 描述
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。 

示例1
输入：15
输出：2
*/


/* 
思路：
本题可以通过先找到距离N最近的两个Fibonacci数，这两个数分别取自距离N的最近的左边一个数L和右边一
个数R，然后通过min(N - L, R - N)找到最小步数。 
*/

#include <iostream>
using namespace std;

int main() {

    int f, f1 = 0, f2 = 1;//首先定义fib数列
    int n = 0;
    cin >> n;
    int left, right;//left,right表示n所在的fib列的区间
    while (1) {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        //如果f<=n 就更新左区间,这里需要加上=
        if (f <= n) {
            left = f;
        } else if (f > n) {
            //如果f>n ,更新右边的最小值,然后就可以break了
            right = f;
            break;
        }
    }

    if (n - left < right - n) {
        cout << n - left << endl;
    } else {
        cout << right - n << endl;
    }
    return 0;
}

//https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=85&&tqId=29846&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking