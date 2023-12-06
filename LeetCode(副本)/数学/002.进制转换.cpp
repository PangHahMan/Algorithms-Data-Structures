/* 描述
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数 

示例1
输入：7 2
输出：111
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    bool flag = false;
    string str, table = "0123456789ABCDEF";
    // 如果是负数，则转成正数，并标记一下
    if (m < 0) {
        m = -m;
        flag = true;
    }
    // 如果m==0,0在任何进制下都是0,所以直接放到str中
    if (m == 0) {
        str += '0';
    }
    //按进制换算成对应的字符串添加到s中
    while (m) {
        str += table[m % n];
        m /= n;
    }

    if (flag == true) {
        str += '-';
    }

    reverse(str.begin(), str.end());
    cout << str << endl;

    return 0;
}

//https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&&tqId=29862&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking