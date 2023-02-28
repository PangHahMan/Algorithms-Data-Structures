/*
给你两个按非递减顺序排列的整数数组nums1和nums2，另有两个整数m和n ，分别表示nums1和nums2中的元素数目。
请你合并nums2到nums1 中，使合并后的数组同样按非递减顺序排列。
 */

/*
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
*/

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int i1 = m - 1;     // nums1中最后数据下标
    int i2 = n - 1;     // nums2中最后数据下标
    int i3 = m + n - 1; // nums1数组最后的下标
    while (i1 >= 0 && i2 >= 0)
    {
        if (nums1[i1] > nums2[i2]) // 将大的放到i3下标中,在分别--
        {
            nums1[i3--] = nums1[i1--];
        }
        else
        {
            nums1[i3--] = nums2[i2--];
        }
    }

    //如果i1走完了，上面的循环结束，i2还没有走完，所以还要循环一遍i2
    //为什么没有i1，因为一旦i2走完了，那i1就是原数组，原封不动即可。
    while (i2 >= 0)
    {
        nums1[i3--] = nums2[i2--];
    }
}
// https://leetcode.cn/problems/merge-sorted-array