/* 描述
给定一个由非负整数填充的m x n的二维数组，现在要从二维数组的左上角走到右下角，请找出路径上的所有数字之和最小的路径。
注意：你每次只能向下或向右移动。


示例1
输入：[[1,2],[5,6],[1,1]]
1 2
5 6
1 1
返回值：8
*/

#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty()) {
            return 0;
        }
        int M = grid.size(); // 行数
        int N = grid[0].size(); // 列数
        vector<vector<int>> ret(M, vector<int>(N, 0)); // 创建一个和grid相同大小的二维数组ret，用于保存最小路径和

        ret[0][0] = grid[0][0]; // 初始化起始位置的路径和为grid[0][0]

        // 初始化第一列的所有数
        for (int i = 1; i < M; i++) {
            ret[i][0] = grid[i][0] + ret[i - 1][0]; // 最小路径和等于当前位置的值加上上方位置的最小路径和
        }

        // 初始化第一行的所有数
        for (int j = 1; j < N; j++) {
            ret[0][j] = grid[0][j] + ret[0][j - 1]; // 最小路径和等于当前位置的值加上左方位置的最小路径和
        }

        // 计算其他位置的最小路径和
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                ret[i][j] = grid[i][j] + min(ret[i][j - 1], ret[i - 1][j]); // 最小路径和等于当前位置的值加上左方和上方位置的最小路径和中的较小值
            }
        }

        return ret[M - 1][N - 1]; // 返回右下角位置的最小路径和
    }
};

//https://www.nowcoder.com/practice/23462ed010024fcabb7dbd3df57c715e?tpId=46&tqId=29115&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking