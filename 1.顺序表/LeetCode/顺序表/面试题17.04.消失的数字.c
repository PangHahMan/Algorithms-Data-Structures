// 数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
int missingNumber(int *nums, int numsSize)
{
    // 思路1  0到n的数字相加，在减去数组中数的和。
    int sum = 0;
    int i = 0;
    for (i = 0; i <= numsSize; i++)
    {
        sum += i;
    }

    for (i = 0; i < numsSize; i++)
    {
        sum -= nums[i];
    }
    return sum;
}

int missingNumber(int *nums, int numsSize)
{
    // 思路2  异或  相同的数字异或得0  0异或任何数字，都得任何数字
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        // 异或上0到numsize 这里缺少一个numsize在循环外在异或一次
        sum ^= i;
        // 异或数组中的数字
        sum ^= nums[i];
    }
    // 异或掉最后一个numsSize
    sum ^= numsSize;
    return sum;
}

// https://leetcode.cn/problems/missing-number-lcci/