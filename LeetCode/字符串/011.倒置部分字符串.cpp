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
using namespace std;

int main() {
    // 创建一个字符串变量s1
    string s1;
    // 从输入流中读取一行，并将结果存储在s1中
    getline(cin, s1);
    // 使用reverse函数将s1中的字符反转
    reverse(s1.begin(), s1.end());

    // 对反转后的字符串进行遍历
    for (int i = 0; i < s1.size();) {
        // 设置一个临时变量j，用于记录单词的终点
        int j = i;
        // 当j没有超出字符串的范围，且当前字符不是空格时，j自增
        while (j < s1.size() && s1[j] != ' ') {
            j++;
        }
        // 使用reverse函数将从i到j的部分反转，即反转每个单词
        reverse(s1.begin() + i, s1.begin() + j);

        // 若j等于s1的大小，说明已经处理完所有的单词，跳出循环
        if (j == s1.size()) {
            break;
        } else {
            // 否则，将i设置为下一个单词的开始位置，继续处理下一个单词
            i = j + 1;
        }
    }
    // 输出处理后的字符串
    cout << s1 << endl;
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