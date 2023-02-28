// ����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
int missingNumber(int *nums, int numsSize)
{
    // ˼·1  0��n��������ӣ��ڼ�ȥ���������ĺ͡�
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
    // ˼·2  ���  ��ͬ����������0  0����κ����֣������κ�����
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        // �����0��numsize ����ȱ��һ��numsize��ѭ���������һ��
        sum ^= i;
        // ��������е�����
        sum ^= nums[i];
    }
    // �������һ��numsSize
    sum ^= numsSize;
    return sum;
}

// https://leetcode.cn/problems/missing-number-lcci/