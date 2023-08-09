// 数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
#include <vector>
using namespace std;

//方法1. 将0到n相加 减去nums数组所有数
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        // 求n,nums缺一个，然后从0开始。n就是nums.size()
        int n = nums.size();
        int sum = 0;
        // 0到n相加
        for (int i = 0; i <= n; i++) {
            sum += i;
        }
        // 相加的值减去数组的每一位值，就是缺失的数字
        for (int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
        }
        return sum;
    }
};


// 方法2：异或
// 思路：异或  相同的数字异或得0  0异或任何数字，都得任何数字.
// 从0开始异或到n，在以此和数组中的异或
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

// https://leetcode.cn/problems/missing-number-lcci/