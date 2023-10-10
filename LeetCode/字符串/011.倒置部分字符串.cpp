/* 
描述
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
输入描述：
每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100
输出描述：
依次输出倒置之后的字符串,以空格分割 

示例1
输入：
I like beijing.

输出：
beijing. like I
*/

/* 【题目解析】:
本题题意很简单,就是将一段字符串中的前后单词交换,以单词为单位逆置.
【解题思路1】:
先将整个字符串逆置过来,再遍历字符串,找出每个单词,对单词逆置.这里我们使用了stl算法中的
reverse,所以这里使用迭代器遍历string 
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    getline(cin, str);
    //翻转句子
    reverse(str.begin(), str.end());
    //翻转单词
    auto start = str.begin();
    while (start != str.end()) {
        auto end = start;
        while (end != str.end() && *end != ' ') {
            end++;
        }
        reverse(start, end);

        if (end == str.end()) {
            break;
        } else {
            start = end + 1;
        }
    }
    cout << str << endl;
}

/* 【解题思路2】:
第二思路是一个比较讨巧的思路,直接利用cin>>s接收输入.遇到空格就结束了,自然就分割开了每个单词,其次将每次接收到的单词拼接到之前串的前面就逆置过来了 
*/
#include <iostream>
#include <string>
using namespace std;
// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
int main() {
    string s1, s2;
    while (cin >> s1)
        s2 = s1 + " " + s2;
    cout << s2 << endl;
    return 0;
}


//https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking