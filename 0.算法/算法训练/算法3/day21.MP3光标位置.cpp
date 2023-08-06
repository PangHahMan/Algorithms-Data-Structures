#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string str;
    while (cin >> n >> str) {
        //第一种情况，n<=4
        int num = 1, first = 1;//初始化位置,都为1
        if (n <= 4) {
            for (int i = 0; i < str.size(); i++) {
                //当只有4张牌的时候,num为1,up就是将1变成个最后的数字,所以num = n
                if (num == 1 && str[i] == 'U') {
                    num = n;
                } else if (num == n && str[i] == 'D') {
                    //当num==n,表示num是最后的位置,如果是down，就表示回到第一个位置
                    num = 1;
                } else if (str[i] == 'U') {
                    num--;
                } else {
                    num++;
                }
            }

            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
            cout << num << endl;
        } else {
            //n>4
            for (int i = 0; i < str.size(); i++) {
                //当num和first都是第一个位置的时候,在按up就都去到了最后一页,那么num就是最后一个位置,而first是最后一页的第一个位置
                if (num == 1 && first == 1 && str[i] == 'U') {
                    num = n;
                    first = n - 3;
                } else if (num == n && first == n - 3 && str[i] == 'D') {
                    //如果num是最后一个位置,并且first是最后一页的第一个位置,在按down就表示去第一页的位置
                    first = num = 1;
                } else if (num == first && first != 1 && str[i] == 'U') {
                    //当num和first在同一个位置,然后frist又不在第一页,按up就表示同时--
                    first--;
                    num--;
                } else if (num == first + 3 && first != n - 3 && str[i] == 'D') {
                    //当first不在最后一页,并且num在first的后3格,在按down就表示同时向后一格
                    first++;
                    num++;
                }//除去上面的情况其余都是num直接++或者--即可
                else if (str[i] == 'U') {
                    num--;
                } else {
                    num++;
                }
            }
            for (int i = first; i <= first + 3; i++) {
                cout << i << " ";
            }
            cout << endl;
            cout << num << endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")


//https://www.nowcoder.com/practice/eaf5b886bd6645dd9cfb5406f3753e15?tpId=37&&tqId=21287&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking