// ����һ���������е�����nums ������ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�� ������ɾ����������³��ȡ�Ԫ�ص����˳�� Ӧ�ñ��� һ�� ��

/*
���룺nums = [0,0,1,1,1,2,2,3,3,4]
�����5, nums = [0,1,2,3,4]
*/

int removeDuplicates(int *nums, int numsSize)
{
    // ˫ָ�� - ������src++������dst++ �ڸ�ֵ
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
    return dst + 1; // dst+1����������³���
}

//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/