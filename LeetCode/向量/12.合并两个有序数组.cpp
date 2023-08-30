/* 
给你两个按非递减顺序排列的整数数组nums1和nums2，另有两个整数m和n ，分别表示nums1和nums2中的元素数目。
请你合并nums2到nums1中，使合并后的数组同样按非递减顺序排列。

示例 1：
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

示例 2：
输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
解释：需要合并 [1] 和 [] 。
合并结果是 [1] 。

示例 3：
输入：nums1 = [0], m = 0, nums2 = [1], n = 1
输出：[1]
解释：需要合并的数组是 [] 和 [1] 。
合并结果是[1]。
注意，因为m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到nums1中。
*/

#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i1 = m - 1;    // nums1中最后数据下标
        int i2 = n - 1;    // nums2中最后数据下标
        int i3 = m + n - 1;// nums1数组最后的下标
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] > nums2[i2])// 将大的放到i3下标中,在分别--
            {
                nums1[i3--] = nums1[i1--];
            } else {
                nums1[i3--] = nums2[i2--];
            }
        }

        //如果i1走完了，上面的循环结束，i2还没有走完，所以还要循环一遍i2
        //为什么没有i1，因为一旦i2走完了，那i1就是原数组，原封不动即可。
        while (i2 >= 0) {
            nums1[i3--] = nums2[i2--];
        }
    }
};