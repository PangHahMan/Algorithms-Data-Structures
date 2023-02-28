#include <stdio.h>

// 插入排序
// 每插入一个值，就和前面的所有数比较，然后将前面的数据挪动到后面，直到有序。
void InSertSort(int *arr, int n)
{
    // 插入n个数，end作为下标开始，tmp是end+1  所以下标n-1
    for (int i = 0; i < n - 1; i++)
    {
        int end = i;
        // tmp暂存值，直到找到有序后，插入最后一个值
        int tmp = arr[end + 1];
        while (end >= 0)
        {
            // 条件成立后，挪动数据，直到条件结束
            if (arr[end] > tmp)
            {
                arr[end + 1] = arr[end];
                end--;
            }
            else
            {
                break;
            }
        }
        // 插入最后一个值，前面end-- 当end为0时，end会越界，所以end+1
        arr[end+1] = tmp;
    }
}

int main()
{
    int arr[] = {11, 64, 12, 85, 23, 46, 89, 34, 35, 78};
    InSertSort(arr, sizeof(arr) / sizeof(int));

    for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}