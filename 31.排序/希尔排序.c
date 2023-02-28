#include <stdio.h>

void ShellSort(int *arr, int n)
{
    // gap为步长，正常的插入排序比较是一个一个比较排序，希尔排序是跳过gap步进行比较排序，比较完后，在进行最后一次插入排序，也就是gap=1时
    int gap = n;
    while (gap > 1)
    {
        // 保证最后一次一定是1,1就是一次直接排序
        gap = gap / 3 + 1;
        for (int i = 0; i < n - gap; i++)
        {
            int end = i;
            int tmp = arr[end + gap];
            while (end >= 0)
            {
                if (tmp < arr[end])
                {
                    arr[end + gap] = arr[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            arr[end + gap] = tmp;
        }
    }
}

int main()
{
    int arr[] = {11, 64, 12, 85, 23, 46, 89, 34, 35, 78};
    ShellSort(arr, sizeof(arr) / sizeof(int));
    for (size_t i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}