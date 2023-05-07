// LeetCode 189.��ת����
// ����һ�����飬�������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
/*
ʾ�� 1:
����: nums = [1,2,3,4,5,6,7], k = 3
���: [5,6,7,1,2,3,4]
����:
������ת 1 ��: [7,1,2,3,4,5,6]
������ת 2 ��: [6,7,1,2,3,4,5]
������ת 3 ��: [5,6,7,1,2,3,4]
*/
#include <stdlib.h>


/* ����һ��ʹ�ö��������
void rotate(int *nums, int numsSize, int k)
{
    // ����������
    int *newArr = (int *)malloc(sizeof(int) * numsSize);
    // ��ԭ�����ֵ��ֵ���������k��λ�ã�(i+k)%numsSize�������γɻ���
    for (int i = 0; i < numsSize; ++i)
    {
        newArr[(i + k) % numsSize] = nums[i];
    }
    // ��󽫿��ٵ����������¿�������
    for (int i = 0; i < numsSize; ++i)
    {
        nums[i] = newArr[i];
    }
} 
*/

void reverse(int *a, int left, int right)
{
    // ���ý���
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
    // �������÷�
    // ����K����ֹkԽ�� ����numsSize
    k %= numsSize;
    // 1.��������
    reverse(nums, 0, numsSize - 1);
    // 2.ǰk������
    reverse(nums, 0, k - 1);
    // 3.��k������
    reverse(nums, k, numsSize - 1);
}

// https://leetcode.cn/problems/rotate-array/