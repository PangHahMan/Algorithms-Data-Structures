/* 描述
定义一个二维数组 N*M ，如 5 × 5 数组下所示：
int maze[5][5] = {
0, 1, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的路线。入口点为[0,0],既第一格是可以走的路。

输入描述：
输入两个整数，分别表示二维数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以走的路。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。

输出描述：
左上角到右下角的最短路径，格式如样例所示。

示例1
输入：
5 5
0 1 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

输出：
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)

示例2
输入：
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 1
0 1 1 1 0
0 0 0 0 0

输出：
(0,0)
(1,0)
(2,0)
(3,0)
(4,0)
(4,1)
(4,2)
(4,3)
(4,4)
说明：
注意：不能斜着走！！  */

#include <iostream>
#include <vector>
using namespace std;

int ROW, COL;
vector<vector<int>> maze;     //迷宫
vector<vector<int>> path_tmp; //走过的下标放到临时路径中
vector<vector<int>> path_best;//最短路径

void MazeTrack(int i, int j) {
    //将走过的路径设置为1
    maze[i][j] = 1;
    path_tmp.push_back({i, j});//插入行列向量,也就是说输出数据path_tmp[i][0]和path_tmp[i][1]; 表示路径

    //判断是否到达出口
    if (i == ROW - 1 && j == COL - 1) {
        //寻找最短路径
        if (path_best.empty() || path_best.size() > path_tmp.size()) {
            //更新best
            path_best = path_tmp;
        }
    }

    //向右走
    if (j + 1 < COL && maze[i][j + 1] == 0) {
        MazeTrack(i, j + 1);
    }
    //向左走
    if (j - 1 >= 0 && maze[i][j - 1] == 0) {
        MazeTrack(i, j - 1);
    }
    //向上走
    if (i - 1 >= 0 && maze[i - 1][j] == 0) {
        MazeTrack(i - 1, j);
    }
    //向下走
    if (i + 1 < ROW && maze[i + 1][j] == 0) {
        MazeTrack(i + 1, j);
    }

    //如果走到这里还没有走出迷宫，说明走错了，需要回溯
    maze[i][j] = 0;     //回溯
    path_tmp.pop_back();//这里会递归回溯,也就是说上面的四种递归条件走不出迷宫都会进行回溯
}

int main() {
    while (cin >> ROW >> COL) {
        maze = vector<vector<int>>(ROW, vector<int>(COL, 0));
        path_tmp.clear();
        path_best.clear();
        //输入迷宫
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                cin >> maze[i][j];
            }
        }

        //从起始点(0.0)开始走
        MazeTrack(0, 0);

        //输出路径
        for (int i = 0; i < path_best.size(); ++i) {
            cout << "(" << path_best[i][0] << "," << path_best[i][1] << ")" << endl;
        }
    }
    return 0;
}


//https://www.nowcoder.com/practice/cf24906056f4488c9ddb132f317e03bc?tpId=37&&tqId=21266&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking