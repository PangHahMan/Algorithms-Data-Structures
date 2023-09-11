/* 
给你一个升序排列的数组 nums ，请你原地删除重复出现的元素，使每个元素只出现一次 ，返回删除后数组的新长度。元素的相对顺序应该保持一致 。然后返回nums中唯一元素的个数。

考虑nums的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

更改数组nums ，使nums的前 k 个元素包含唯一元素，并按照它们最初在nums中出现的顺序排列。nums的其余元素与nums的大小不重要。返回k 。

示例 1：
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。

示例 2：
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
 */


#include <vector>
using namespace std;
//双指针
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        //初始化为1，然后从后面跟前面比较
        int slow = 1, fast = 1;
        while (fast < nums.size()) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow++] = nums[fast];
            }
            fast++;
        }

        return slow;
    }
};
//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
