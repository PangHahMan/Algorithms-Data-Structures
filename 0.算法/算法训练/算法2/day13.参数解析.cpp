/* 描述
在命令行输入如下命令：
xcopy /s c:\\ d:\\e，

各个参数如下：
参数1：命令字xcopy
参数2：字符串/s
参数3：字符串c:\\
参数4: 字符串d:\\e
请编写一个参数解析程序，实现将命令行各个参数解析出来。
解析规则：
1.参数分隔符为空格
2.对于用""包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy /s "C:\\program files" "d:\"时，参数仍然是4个，第3个参数应该是字符串C:\\program files，而不是C:\\program，注意输出参数时，需要将""去掉，引号不存在嵌套情况。
3.参数不定长
4.输入由用例保证，不会出现不符合要求的输入

输入描述：
输入一行字符串，可以有空格

输出描述：
输出参数个数，分解后的参数，每个参数都独占一行

示例1
输入：xcopy /s c:\\ d:\\e
输出：4
      xcopy
      /s
      c:\\
      d:\\e 
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

void cmdLineParse(const string &str) {

    string tmp;
    vector<string> svec;
    bool flag = true;//flag为true表示遇到空格算是一个子串，flase表示在双引号中的空格
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ' && flag == true) {
            svec.push_back(tmp);
            tmp.clear();//插入后清空字符串
        } else if (str[i] == '"') {
            flag = !flag;    //遇到" 就取反
        } else {
            //正常字符
            tmp += str[i];
        }
    }
    svec.push_back(tmp);//尾插最后一个子串,最后的子串没有空格

    cout << svec.size() << endl;
    for (auto &tmp: svec) {
        cout << tmp << endl;
    }
}

int main() {
    string str;
    while (getline(cin, str)) {
        cmdLineParse(str);
    }
    return 0;
}

//https://www.nowcoder.com/practice/668603dc307e4ef4bb07bcd0615ea677?tpId=37&&tqId=21297&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking