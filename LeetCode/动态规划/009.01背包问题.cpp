/* 描述
有n个物品和一个大小为m的背包. 给定数组A表示每个物品的大小和数组V表示每个物品的价值.
问最多能装入背包的总价值是多大?

样例 1：
输入：
m = 10
A = [2, 3, 5, 7]
V = [1, 5, 2, 4]
输出：9
解释：装入 A[1] 和 A[3] 可以得到最大价值, V[1] + V[3] = 9

样例 2：
输入：
m = 10
A = [2, 3, 8]
V = [2, 5, 8]
输出：10
*/

/*
这是一个经典的0-1背包问题，我们可以使用动态规划（DP）的方法来解决。每次考虑取还是不取这个物品。
在动态规划设计的过程中，我们首先需要设计状态表示，然后设计状态转移方程。在这个问题中，我们可以这样设计：
状态表示：dp[i][j] 表示前i个物品中，体积不超过j的情况下，总价值的最大值。
状态转移方程：dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i - 1]] + V[i - 1]) （这里的 j >= A[i - 1] ）
初始状态：dp[i][0] = 0 （不取任何物品）
这里需要注意的是，在状态转移方程中，我们每次在更新dp[i][j]的时候，都是从dp[i - 1][j]和dp[i - 1][j - A[i - 1]] + V[i - 1]中选择一个最大的值，也就相当于是，在面对第i个物品的时候，选择取或者是不取。

例子：
背包容量 m=10, 物品大小 A=[2,3,5,7], 物品价值 V=[1,5,2,4]
初始，物品(i=0)未进入时，各容量背包的价值为: dp[0][..]=0（用X表示）
dp:
X   0   0   0   0   0   0   0   0   0   0
-   -   -   -   -   -   - -   -   -   -   -
物品 i=1 进入后，大小为2，价值是1，各容量背包价值更新：
dp:
X   0   1   1   1   1   1   1   1   1   1
-   -   -   -   -   -   - -   -   -   -   -
物品 i=2 进入后，大小为3，价值是5，各容量背包价值更新：
dp:
X   0   1   5   6   6   6   6   6   6   6
-   -   -   -   -   -   - -   -   -   -   -
物品 i=3 进入后，大小为5，价值是2，各容量背包价值更新：
dp:
X   0   1   5   6   7   8   10  11  11  11
-   -   -   -   -   -   - -   -   -   -   -
物品 i=4 进入后，大小为7，价值是4，各容量背包价值更新：
dp:
X   0   1   5   6   7   8   10  11  13  14
-   -   -   -   -   -   - -   -   -   -   -
最后 dp[4][10]=14，表示物品1至4进入容量为10背包时的最大价值
*/
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int backPackII(int m, vector<int> &a, vector<int> &v) {
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        //i表示的是商品的个数，j表示的是背包的容量设置
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j < a[i - 1]) {
                    //j<a[i-1]说明当前物品不能放入背包,背包容量不够,那么就不放入背包，dp为上一行不变
                    dp[i][j] = dp[i - 1][j];
                } else {
                    //背包可以放入,则更新背包
                    //dp[i-1][j-a[i-1]] 表示减去当前背包的容量之后的最大价值+当前背包的价值
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + v[i - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

//https://www.lintcode.com/problem/125/