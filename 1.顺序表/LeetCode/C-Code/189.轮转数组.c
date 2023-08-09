
#include <stdlib.h>

/* void rotate(int *nums, int numsSize, int k) {
    int *newArr = (int *) malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        newArr[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; ++i) {
        nums[i] = newArr[i];
    }
} */


void reverse(int *a, int left, int right) {
    while (left < right) {
        int tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
        left++;
        right--;
    }
}

void rotate(int *nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

// https://leetcode.cn/problems/rotate-array/