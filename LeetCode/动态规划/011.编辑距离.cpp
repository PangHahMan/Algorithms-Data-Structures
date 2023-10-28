/* 
描述
给定两个单词word1和word2，请计算将word1转换为word2至少需要多少步操作。
你可以对一个单词执行以下3种操作：
a）在单词中插入一个字符
b）删除单词中的一个字符
c）替换单词中的一个字符

示例1
输入："b",""
返回值：1

示例2
输入："ab","bc"
返回值：2
*/

/* 思路：
编辑距离问题实际就是比较两个字符串的相似度。假设你有两个字符串，你可以进行插入、删除、替换这三种操作，那么如何才能用最少的操作次数，把第一个字符串变成跟第二个字符串一样呢？

我们使用动态规划都有一个通用的思路，就是把大问题拆成小问题。也就是说，如果我们知道了字符串A的前m个字符变成字符串B的前n个字符需要多少步，那么我们就可以很容易地知道字符串A的前m+1个字符变成字符串B的前n+1个字符需要多少步。

那么具体怎么做呢？这就牵涉到我们的状态转移方程，让我们以dp[i][j]来表示字符串A的前i个字符变成字符串B的前j个字符需要的最小步数。

如果A的第i个字符和B的第j个字符相同，我们不需要做任何操作，可以直接从dp[i - 1][j - 1]状态转移到dp[i][j]，也就是说dp[i][j] = dp[i - 1][j - 1]。

如果A的第i个字符和B的第j个字符不相同，那么我们有三种操作方式：插入、删除、替换。这三种操作分别对应了以下三种状态转移：

插入操作：在A的第i个字符之后插入一个和B的第j个字符相同的字符，那么B的前j个字符就变成了前j+1个字符，所以dp[i][j] = dp[i][j - 1] + 1；
删除操作：删除A的第i个字符，那么A的前i个字符就变成了前i-1个字符，所以dp[i][j] = dp[i - 1][j] + 1；
替换操作：直接把A的第i个字符替换成B的第j个字符，所以dp[i][j] = dp[i - 1][j - 1] + 1。

      "" r  o  s
   "" 0  1  2  3
   h  1  1  2  3
   o  2  2  1  2
   r  3  2  2  2
   s  4  3  3  2
   e  5  4  4  3
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        //初始化二维数组
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    /* 
                    三种操作
                    删除: 比如从 "hor" 变到 "ro"，实际操作就是删除 "hor" 的尾字符 r，所需步数是从 "ho" 变到 "ro" 的步数 + 1，所以状态转移方程为 dp[i][j] = dp[i - 1][j] + 1；
                    插入: 比如从 "ho" 变到 "ros"，实际操作就是在 "ho" 右侧插入一个 s，所需步数是从 "ho" 变到 "ro" 的步数 + 1，所以状态转移方程为 dp[i][j] = dp[i][j - 1] + 1；
                    替换: 比如从 "hor" 变到 "ros"，实际操作就是用 s 替换 "hor" 的尾字符 r，所需步数是从 "ho" 变到 "ro" 的步数 + 1，所以状态转移方程为 dp[i][j] = dp[i - 1][j - 1] + 1。
                     */
                    dp[i][j] = min(dp[i - 1][j],min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
            }
        }

        return dp[n][m];
    }
};

//https://leetcode.cn/problems/edit-distance/submissions/