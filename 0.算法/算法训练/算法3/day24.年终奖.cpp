/* 描述
小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一个6*6的棋盘上进行，上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，一路上的格子里的礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。

给定一个6*6的矩阵board，其中每个元素为对应格子的礼物价值,左上角为[0,0],请返回能获得的最大价值，保证每个礼物价值大于100小于1000。
*/


#include <algorithm>
#include <vector>
using namespace std;
class Bonus {
public:
    int getMost(vector<vector<int>> board) {
        int row = board.size();
        int col = board[0].size();
        //初始化，allPrice表示累加值
        vector<vector<int>> allPrice(row, vector<int>(col, 0));
        //初始化第一个
        allPrice[0][0] = board[0][0];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                //起点坐标已经初始化，可以直接跳过
                if (i == 0 && j == 0) {
                    continue;
                }
                //第一行的值，都是通过往右走得来的，当前累加值等于当前礼物价值加上左边的累加值
                if (i == 0) {
                    allPrice[i][j] = allPrice[i][j - 1] + board[i][j];
                } else if (j == 0) {
                    //如果是第一列，就只能往下走
                    allPrice[i][j] = allPrice[i - 1][j] + board[i][j];
                } else {
                    //除去两个临界边，剩下的就是既能向右走，也能向下走，
                    //这时候就要考虑走到当前点的所有可能得情况，也就是走到当前点
                    //各自路径的和是不是这些所有到达该点路径当中最大的了
                    allPrice[i][j] = max(allPrice[i][j - 1], allPrice[i - 1][j]) + board[i][j];
                }
            }
        }
        //返回右下角的值
        return allPrice[row - 1][col - 1];
    }
};

//https://www.nowcoder.com/practice/72a99e28381a407991f2c96d8cb238ab?tpId=49&&tqId=29305&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking