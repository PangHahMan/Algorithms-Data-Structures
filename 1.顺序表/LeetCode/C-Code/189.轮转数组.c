// LeetCode 189.轮转数组
// 给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
/*
示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
*/
#include <stdlib.h>

/* 方法一：使用额外的数组
void rotate(int *nums, int numsSize, int k)
{
    // 开辟新数组
    int *newArr = (int *)malloc(sizeof(int) * numsSize);
    // 将原数组的值赋值到新数组第k个位置，(i+k)%numsSize让数组形成环形
    for (int i = 0; i < numsSize; ++i)
    {
        newArr[(i + k) % numsSize] = nums[i];
    }
    // 最后将开辟的数组在重新拷贝回来
    for (int i = 0; i < numsSize; ++i)
    {
        nums[i] = newArr[i];
    }
} 
*/

void reverse(int *a, int left, int right)
{
    // 逆置交换
    while (left < right)
    {
        int tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
        left++;
        right--;
    }
}

void rotate(int *nums, int numsSize, int k)
{
    // 三次逆置法
    // 重置K，防止k越界 超过numsSize
    k %= numsSize;
    // 1.整体逆置
    reverse(nums, 0, numsSize - 1);
    // 2.前k个逆置
    reverse(nums, 0, k - 1);
    // 3.后k个逆置
    reverse(nums, k, numsSize - 1);
}

// https://leetcode.cn/problems/rotate-array/