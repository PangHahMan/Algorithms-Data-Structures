/* 描述
考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
输入描述：输入第一行为字符串个数n(n ≤ 100) 接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成
输出描述：如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",如果根据长度排列而不是字典序排列输出"lengths",
如果两种方式都符合输出"both"，否则输出"none"

示例1
输入：3
a
aa
bbb

输出：
both
 */

/* 
思路：
思路很简单，将接受的字符串都放到vector容器中，利用string的operator>=运算符重载来按ascii比较字符
串，利用string的size来比较字符串的长度 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v;
    v.resize(n);
    for (auto &str: v) {
        cin >> str;
    }

    bool length = true, cstr = true;
    for (int i = 1; i < n; i++) {
        //任意两个字符串长度不同所以不能相等
        if (v[i - 1].size() > v[i].size()) {
            length = false;
        }

        if (v[i - 1] > v[i]) {
            cstr = false;
        }
    }

    if (length && cstr) {
        cout << "both" << endl;
    } else if (length) {
        cout << "lengths" << endl;
    } else if (cstr) {
        cout << "lexicographically" << endl;
    } else {
        cout << "none" << endl;
    }
    return 0;
}

//https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking