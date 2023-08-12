//https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe
/* 数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。
比如，对于24来说，把2和4相加得到6，由于6是一位数，因此6是24的数根。
再比如39，把3和9加起来得到12，由于12不是一位数，因此还得把1和2加起来，最后得到3，这是一个一位数，因此3 是39 的数根。
现在给你一个正整数，输出它的数根。

输入描述:
输入包含多组数据。

每组数据数据包含一个正整数n（1≤n≤10E1000）。

输出描述:
对应每一组数据，输出该正整数的数根。 

示例1
输入
24   2+4 = 6
39   3+9=12  1+2 =3

输出
6
3
*/

#include <iostream>
#include <string>
int numRoot(int num) {
    int nroot = 0;
    while (num > 0) {
        /*每次只获取个位数字---个位数+十位数*/
        nroot += num % 10;
        num /= 10;
    }
    while (nroot > 9) {
        nroot = numRoot(nroot);
    }
    return nroot;
}

int main() {
    //需要string来保存数字，因为数字非常大
    std::string origin;
    while (std::cin >> origin) {
        int sum = 0;
        //先将每一位进行相加得到总和，防止数字过大
        for (int i = 0; i < origin.length(); i++) {
            sum += origin[i] - '0';
        }
        //对总和求树根
        std::cout << numRoot(sum) << std::endl;
    }
    return 0;
}