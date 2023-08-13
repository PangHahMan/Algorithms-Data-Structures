// ����һ���������е�����nums ������ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�� ������ɾ����������³��ȡ�Ԫ�ص����˳�� Ӧ�ñ��� һ�� ��

/*
���룺nums = [0,0,1,1,1,2,2,3,3,4]
�����5, nums = [0,1,2,3,4]
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