#include <stdio.h>
#include <stdlib.h>
// 时间复杂度0(N+range),空间复杂度O(range)
// 算法的效率很高，但有局限性，只适用于整型值排序，如果range过大，空间复杂度就比较高
void CountSort(int *a, int n)
{
    int max = a[0], min = a[0];
    // 找出最大的和最小的，算出范围
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];

        if (a[i] < min)
            min = a[i];
    }
    // 范围+1  开出范围个空间
    int range = max - min + 1;
    int *tmp = (int *)calloc(range, sizeof(int));
    if (tmp == NULL)
    {
        perror("calloc fail");
        exit(-1);
    }
    // 统计次数
    for (int i = 0; i < n; i++)
    {
        // 给tmp数组出现a[i]的数字计数
        tmp[a[i] - min]++;
    }

    // 排序 - 将tmp数组中的数覆盖到a数组中
    int k = 0;
    for (int j = 0; j < range; j++)
    {
        if (tmp[j] != 0)
        {
            while (tmp[j]--)
            {
                // a[k]的值等于tmp数组下标加上最小的范围的值
                a[k++] = j + min;
            }
        }
    }
    free(tmp);
}

int main()
{
    int arr[] = {11, 64, 12, 85, 23, 46, 89, 34, 35, 78};
    CountSort(arr, sizeof(arr) / sizeof(int));
    for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}