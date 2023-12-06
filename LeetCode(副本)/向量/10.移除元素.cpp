/*
给你一个数组nums和一个值val，你需要原地移除所有数值等于val的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用O(1)额外空间并原地修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 */

/*
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
*/

#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int i = 0, j = 0;//双指针
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
// https://leetcode.cn/problems/remove-element
