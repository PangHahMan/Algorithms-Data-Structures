/* 
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。


示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]

示例 2:
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]

*/

#include <vector>
using namespace std;
class Solution {
public:
    void reverse(vector<int> &nums, int begin, int end) {
        while (begin < end) {
            swap(nums[begin], nums[end]);
            begin++;
            end--;
        }
    }

    void rotate(vector<int> &nums, int k) {
        // 需要使k重置，形成环形的数组
        k %= nums.size();
        // 1.整体逆置
        reverse(nums, 0, nums.size() - 1);
        // 2.逆置k左边
        reverse(nums, 0, k - 1);
        // 3.逆置k右边
        reverse(nums, k, nums.size() - 1);
    }
};

//https://leetcode.cn/problems/rotate-array/description/