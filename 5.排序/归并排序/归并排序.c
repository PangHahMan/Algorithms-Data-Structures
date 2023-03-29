#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 归并排序 - 两段有序区间，依次比较取小的尾插
// 怎么保证每次都是有序的，递归到最后的数，在开始排序，递归回来，每次就都是有序的
void _MergeSort(int *a, int left, int right, int *tmp)
{
    if (left >= right)
        return;

    // 分两段区间
    int mid = (left + right) / 2;
    //[left, mid] [mid+1, right] 递归让子区间有序
    // 递归左区间
    _MergeSort(a, left, mid, tmp);
    // 递归右区间
    _MergeSort(a, mid + 1, right, tmp);

    // 开始归并
    int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
    int i = left;
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] <= a[begin2])
            tmp[i++] = a[begin1++];
        else
            tmp[i++] = a[begin2++];
    }
    // begin1<=end 说明begin1还没有走完，走完剩下的
    while (begin1 <= end1)
    {
        tmp[i++] = a[begin1++];
    }

    while (begin2 <= end2)
    {
        tmp[i++] = a[begin2++];
    }
    // 将tmp数组覆盖到a数组中，下标从每次归并的left开始
    // right-left 是小标，换算成数组个数，要+1
    memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int *a, int n)
{
    int *tmp = (int *)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    // 传值为下标值
    _MergeSort(a, 0, n - 1, tmp);

    free(tmp);
    tmp = NULL;
}

int main()
{
    int arr[] = {21, 64, 12, 85, 23, 46, 89, 34, 35, 78};
    MergeSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}