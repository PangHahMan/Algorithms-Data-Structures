// 给你一个升序排列的数组nums ，请你原地删除重复出现的元素，使每个元素只出现一次 ，返回删除后数组的新长度。元素的相对顺序 应该保持 一致 。

/*
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
*/

int removeDuplicates(int *nums, int numsSize)
{
    // 双指针 - 如果相等src++，否则dst++ 在赋值
    int src = 0, dst = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[src] == nums[dst])
        {
            src++;
        }
        else
        {
            dst++;
            nums[dst] = nums[src++];
        }
    }
    return dst + 1; // dst+1才是数组的新长度
}

//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/