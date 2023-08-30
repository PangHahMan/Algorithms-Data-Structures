/* 
数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

示例 1：
输入：[3,0,1]
输出：2
 
示例 2：
输入：[9,6,4,2,3,5,7,0,1]
输出：8
*/

#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum ^= i;
        }

        for (int i = 0; i < nums.size(); i++) {
            sum ^= nums[i];
        }
        return sum;
    }
};

//https://leetcode.cn/problems/missing-number-lcci/description/