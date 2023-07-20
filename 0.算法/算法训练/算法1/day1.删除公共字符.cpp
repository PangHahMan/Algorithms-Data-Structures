/* 描述
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”

输入描述：
每个测试输入包含2个字符串

输出描述：
输出删除后的字符串

示例1
输入：
They are students. 
aeiou

输出：
Thy r stdnts.
 */

/* 本题如果使用传统的暴力查找方式，如判断第一个串的字符是否在第二个串中，在再挪动字符删除这个字符的方式，效率为O(N^2)，效率太低，很难让人满意。
1. 将第二个字符串的字符都映射到一个hashtable数组中，用来判断一个字符在这个字符串。
2. 判断一个字符在第二个字符串，不要使用删除，这样效率太低，因为每次删除都伴随数据挪动。这里可以考虑使用将不在字符添加到一个新字符串，最后返回新新字符串。 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int HashTable[256] = {0};
    // 将str2中的字符映射到HashTable数组中
    for (int i = 0; i < str2.size(); i++) {
        HashTable[str2[i]]++;
    }

    string ret;
    for (int i = 0; i < str1.size(); i++) {
        if (HashTable[str1[i]] == 0) {
            ret += str1[i];
        }
    }

    cout << ret << endl;
}
// 64 位输出请用 printf("%lld")