/*
给你一个数组 nums?和一个值 val，你需要 原地 移除所有数值等于?val?的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 */

/*
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
*/

int removeElement(int *nums, int numsSize, int val)
{
    // 双指针 - 判断是否相同，相同的话src++，不相同则把src给dst
    int dst = 0, src = 0;
    for(int i =0 ;i<numsSize;i++)
    {
        if(nums[src]==val)
        {
            src++;
        }
        else
        {
            nums[dst++]=nums[src++];
        }
    }
    return dst;  //dst最后会++就是数组新长度
}
// https://leetcode.cn/problems/remove-element
