/* 描述
读入一个字符串str，输出字符串str中的连续最长的数字串 
*/


//遍历字符串，使用cur去记录连续的数字串，如果遇到不是数字字符，则表示一个连续的数字串结束了，则将数字串跟之前的数字串比较，如果更长，则更新更长的数字串更新到res。

#include <iostream>
using namespace std;

int main() {
    string str, cur, ret;
    cin >> str;
    for (int i = 0; i <= str.length(); i++) {
        //注意这里的结束条件i <= str.length(),为了防止最长数字串在最后而没有进入循环，导致没有判断，当然也可以在for循环结束在判断一次ret.size和cur.size
        // 数字+=到cur
        if (str[i] >= '0' && str[i] <= '9') {
            cur += str[i];
        } else {
            // 找出更长的字符串，则更新字符串
            if (cur.size() > ret.size()) {
                ret = cur;
            } else {
                cur.clear();
            }
        }
    }
    cout << ret << endl;
    return 0;
}


//https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&&tqId=29864&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking