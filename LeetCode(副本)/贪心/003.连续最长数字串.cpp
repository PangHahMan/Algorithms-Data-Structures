/* 描述
读入一个字符串str，输出字符串str中的连续最长的数字串 
*/
//遍历字符串，使用cur去记录连续的数字串，如果遇到不是数字字符，则表示一个连续的数字串结束了，则将数字串跟之前的数字串比较，如果更长，则更新更长的数字串更新到res。

#include <iostream>
using namespace std;

int main() {
    string str, cur, ret;
    while (getline(cin, str)) {
        for (int i = 0; i < str.size(); i++) {
            //追加数字串
            while (str[i] >= '0' && str[i] <= '9') {
                cur += str[i++];
            }
            //更新最长数字串
            if (cur.size() > ret.size()) {
                ret = cur;
            }
            //清空cur,寻找下一个数字串
            cur.clear();
        }

        cout << ret << endl;
    }
    return 0;
}
//https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&&tqId=29864&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking