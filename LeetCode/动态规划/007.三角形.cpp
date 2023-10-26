/* 描述
给出一个三角形，计算从三角形顶部到底部的最小路径和，每一步都可以移动到下面一行相邻的数字，
例如，给出的三角形如下：
[[20],[30,40],[60,50,70],[40,10,80,30]]
最小的从顶部到底部的路径和是20 + 30 + 50 + 10 = 110。
注意：
如果你能只用O（N）的额外的空间来完成这项工作的话，就可以得到附加分，其中N是三角形中的行总数。
*/


#include <algorithm>
#include <vector>
using namespace std;
/* 
            20
        30        40
    60      50          70
40      10        80        30
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.empty()) {
            return 0;
        }
        int row = triangle.size();


        //从第2层开始,下标对应为1
        for (int i = 1; i < row; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == i) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }

        //统计完了所有的路径结果 开始寻找最小的路径
        int result = triangle[row - 1][0];
        int col = triangle[row - 1].size();
        for (int i = 1; i < col; i++) {
            result = min(result,triangle[row-1][i]);
        }

        return result;
    }
};

//https://www.nowcoder.com/practice/2b7995aa4f7949d99674d975489cb7da?tpId=46&tqId=29060&tPage=2&rp=2&ru=/ta/leetcode&qru=/ta/leetcode/question-rankin