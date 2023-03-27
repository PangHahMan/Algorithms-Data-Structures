#include <stdio.h>

void Swap(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// 选择排序 - 没优化

/*
void SelectSort(int *arr, int n)
{
    //从第i个数开始，找后面的所有数，找最小的数，然后和第一个数交换
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                // 更新min的坐标
                min = j;
            }
        }
        Swap(&arr[min],&arr[i]);
    }
}
*/

// 选择排序 - 优化
void SelectSort(int *arr, int n)
{
    // 记录左右的下标，最小的放到left下标位置，最大的放到right的位置
    int left = 0, right = n - 1;
    // 当left<right继续
    while (left < right)
    {
        int min = left, max = left;
        // 从剩下的去找最小，最大的数。
        for (int i = left + 1; i <= right; i++)
        {
            // 找最小的数字下标
            if (arr[i] < arr[min])
            {
                min = i;
            }
            // 找最大的数字下标
            if (arr[i] > arr[max])
            {
                max = i;
            }
        }
        // 最小的数和left交换
        Swap(&arr[min], &arr[left]);
        // 如果max==left的话，刚刚left和min交换了，此时，min就变成了最大
        if (max == left)
        {
            max = min;
        }

        // 最大的数和right交换
        Swap(&arr[max], &arr[right]);
        left++;
        right--;
    }
}

int main()
{
    int arr[] = {11, 64, 12, 85, 23, 46, 89, 34, 35, 78};
    SelectSort(arr, sizeof(arr) / sizeof(int));
    for (size_t i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}