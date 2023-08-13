// 给你一个升序排列的数组nums ，请你原地删除重复出现的元素，使每个元素只出现一次 ，返回删除后数组的新长度。元素的相对顺序 应该保持 一致 。

/*
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
*/

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    
    int fast = 1, slow = 1;
    while (fast < numsSize) {
        if (nums[fast] != nums[fast - 1]) {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}

//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/