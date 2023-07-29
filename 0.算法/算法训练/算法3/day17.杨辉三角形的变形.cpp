/* 
三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数、左上角数和右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。

求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3，输入2则输出-1。
输入描述：
输入一个int整数

输出描述：
输出返回的int值

示例1
输入：4
输出：3
*/

/* 思路：
按照题目意思，可以发现第n行有2n - 1个元素，第i,j元素等于上一行第j - 2,j - 1,j三列元素之和，每一行的第
一列和最后一列都为1，如果是第二列，则只是两个元素之和。 
杨辉三角形每行对应偶数位置
{-1,-1,2,3,2,4,2,3,2,4,...};
*/

#include <iostream>
using namespace std;

int main() {
    int nRow = 0;
    while (cin >> nRow) {
        int myInt[] = {2, 3, 2, 4};
        if (nRow <= 2) {
            cout << -1 << endl;
        } else if (nRow > 2) {
            cout << myInt[(nRow + 1) % 4] << endl;
        }
    }
    return 0;
}
//https://www.nowcoder.com/practice/8ef655edf42d4e08b44be4d777edbf43?tpId=37&&tqId=21276&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking