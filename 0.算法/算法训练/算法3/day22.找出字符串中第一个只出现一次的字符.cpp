/* 描述
找出字符串中第一个只出现一次的字符

输入描述：
输入一个非空字符串

输出描述：
输出第一个只出现一次的字符，如果不存在输出-1

示例1
输入：asdfasdfo

输出：o
*/


#include <iostream>
#include <string>
using namespace std;


//思路1：暴力法 O(N*2)
char getFirst_OneChar(const string &str) {
    for (int i = 0; i < str.size(); i++) {
        int j;
        for (j = 0; j < str.size() - 1; j++) {
            if (i == j) {
                continue;
            }
            if (str[i] == str[j]) {
                break;
            }
        }
        if (j >= str.size()) {
            return str[i];
        }
    }
    return -1;
}


//思路2：哈希法 O(N)
char getFirst_OneChar(const string &str) {
    int hash[256] = {0};
    for (int i = 0; i < str.size(); i++) {
        hash[str[i]]++;
    }

    for (int i = 0; i < str.size(); i++) {
        if (hash[str[i]] == 1) {
            return str[i];
        }
    }

    return -1;
}

//思路3： string类函数查找法
char getFirst_OneChar(const string &str) {
    for(int i =0;i<str.size();i++){
        int index1 = str.find(str[i]);
        int index2 = str.rfind(str[i]);
        if(index1 == index2){
            return str[i];
        }
    }
    return -1;
}

int main() {
    string str;
    while (cin >> str) {
        char res = getFirst_OneChar(str);
        if (res == -1) {
            cout << -1 << endl;
        } else {
            cout << res << endl;
        }
    }
}

//https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking