/* 描述
给定一个仅由小写字母组成的字符串。现在请找出一个位置，删掉那个字母之后，字符串变成回文。请放心总会有一个合法的解。如果给定的字符串已经是一个回文串，那么输出-1。

输入描述：
第一行包含T，测试数据的组数。后面跟有T行，每行包含一个字符串。
输出描述：
如果可以删去一个字母使它变成回文串，则输出任意一个满足条件的删去字母的位置（下标从0开始）。例如：

示例1
输入：3
aaab
baa
aaa

输出：
3
0
-1
*/

#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string &str, int start, int end) {
    while (start < end) {
        if (str[start++] != str[end--]) {
            return false;
        }
    }
    return true;
}

int solve(string &str) {
    int start = 0;
    int end = str.size() - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            if (is_palindrome(str, start + 1, end)) {
                return start;
            }
            if (is_palindrome(str, start, end - 1)) {
                return end;
            }
        }
        start++;
        end--;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        cout << solve(str) << endl;
    }
    return 0;
}

//https://www.nowcoder.com/practice/b6edb5ca15d34b1eb42e4725a3c68eba?