/* 描述
二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。 
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。
*/

/* 
示例1
输入：3 2
输出：4
1表示可以放，0表示不能放
1 1
1 1
0 0

 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int w, h, count = 0;
    cin >> w >> h;
    vector<vector<int>> a;
    a.resize(w);
    for (auto &e: a) {
        //将所有的格子初始化为1
        e.resize(h, 1);
    }

    //遍历二维数组
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (a[i][j] == 1) {
                count++;
                //标记不能放蛋糕的位置,<w和h是为了防止越界
                //能放蛋糕的位置就是行列间隔不大于2
                if ((i + 2) < w) {
                    a[i + 2][j] = 0;
                }

                if ((j + 2) < h) {
                    a[i][j + 2] = 0;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}


//https://www.nowcoder.com/practice/1183548cd48446b38da501e58d5944eb?tpId=85&&tqId=29840&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking