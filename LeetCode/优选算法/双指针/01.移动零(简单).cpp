/* https://leetcode.cn/problems/move-zeroes/description/
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

示例 2:
输入: nums = [0]
输出: [0] 
*/

/*思想： 
1.使用两个指针cur和dest。cur指针用于遍历数组，dest指针用于指向最后一个非零元素的位置。
2.初始化时cur设置为0，即从数组的开头开始遍历；dest设置为-1，因为开始时还没有遇到任何非零元素，可以理解为非零元素数组的下一个插入位置。
3.当cur指针遍历数组时，如果遇到一个非零元素，则将dest指针增加1，然后将当前的非零元素与dest指针所指向的位置（即最后一个非零元素的下一个位置）交换。这保证了非零元素的顺序不会改变。
4.如果cur指针遇到的是零元素，则不对dest进行操作，这样零元素就会被留在原地，而非零元素则会向数组的前端移动。
5.遍历完成后，所有非零元素都被移动到数组前端，dest指针后面的所有元素都是零，从而实现将所有零元素移动到数组末尾的目标。
 */

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        for (int cur = 0, dest = -1; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                swap(nums[++dest], nums[cur]);
            }
        }
    }
};