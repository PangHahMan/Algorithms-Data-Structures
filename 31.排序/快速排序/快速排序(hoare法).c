#include <stdio.h>
void Swap(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void InSertSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int end = i;
        int tmp = arr[end + 1];
        while (end >= 0)
        {
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
        arr[end + 1] = tmp;
    }
}

// 快速排序的优化(三数取中)
// 如果一边的区间非常的多，那么递归的二叉树结构的层数就会增大，那么效率就会变低，所以采用三数取中，找中间值，让key划分两个对等的区间
int GetMidIndex(int *a, int left, int right)
{
    int mid = (left + right) / 2;
    if (a[left] < a[mid])
    {
        if (a[mid] < a[right])
            return mid;
        else if (a[left] < a[right])
            return right;
        else // a[right]<a[left]
            return left;
    }
    else
    {
        if (a[left] < a[right])
            return left;
        else if (a[right] < a[mid])
            return mid;
        else // a[right]<a[left]
            return right;
    }
}

// 快速排序hoare版本
// 一堆数据 左边做key，右边先走，右边找到比key小的停住，左边在找比key大的，然后交换。相遇后，与key交换
// 如果左边做key，右边先走，如果右边做key，左边先走
// 左边做key，右边先走。保证相遇位置，比key要小
// 1、相遇，右边停住的，左边遇到右边，相遇位置就是右边停住的位置
// 2、相遇，左边停住的，右边遇到左边，相遇位置就是左边停住的位置
// 单趟排序：左边比key小，右边比key大
// 1、分割出左右区间，左区间比key小，右区间比key大
// 2、key已经落到了他的正确位置(排序后的最终位置)剩下的问题就是 左区间的递归有序，右区间的递归有序，那么整体就OK了
int PartSort(int *a, int left, int right)
{
    int mid = GetMidIndex(a, left, right);
    Swap(&a[left], &a[mid]);

    int key = left;
    // 当left<right 开始走
    while (left < right)
    {
        // 右边先走，找小
        // 这里left<right 是因为，可能a[right]一直比a[key]大，那么right一直会减下去
        while (left < right && a[right] >= a[key])
        {
            --right;
        }
        // 左边再走，找大
        while (left < right && a[left] <= a[key])
        {
            ++left;
        }

        Swap(&a[left], &a[right]);
    }
    // 最后相遇的位置和key交换，left和right都可以
    Swap(&a[left], &a[key]);
    key = left;
    return key;
}

// 这里的left，right都为下标
void QuickSort(int *a, int left, int right)
{
    // 当左区间只有一个数的时候，传参，left, key - 1  left=0，key=-1  left>right
    // 当右区间只有一个数的时候，传参，key + 1, right left=1，right = 0
    // 还有一种可能一开始就一个数,left和right相等
    if (left >= right)
    {
        return;
    }

    // 小区间优化，减少递归次数
    if ((right - left) < 15)
    {
        // a+left 因为递归的层数，数组区间是动态的，左边的下标是不确定的
        InSertSort(a + left, right - left + 1);
    }
    else
    {
        int key = PartSort(a, left, right);
        // 数组被划分为三个区间left - key - right
        // 左区间为left - key-1， 右区间为key+1 - right
        QuickSort(a, left, key - 1);
        QuickSort(a, key + 1, right);
    }
}

int main()
{
    int arr[] = {11, 64, 12, 85, 23, 46, 89, 34, 35, 78};
    QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}