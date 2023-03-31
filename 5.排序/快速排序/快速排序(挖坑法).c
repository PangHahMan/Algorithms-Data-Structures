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

// 挖坑法
// 1.先将第一个数据放在临时变量key中，形成一个坑位
// 2.右边找小，找到后，将值给left，留下一个坑位
// 3.左边找大，找到后，将值给right，留下一个坑位
// 4.相遇后，将key给相遇的位置
int PartSort(int *a, int left, int right)
{
    int mid = GetMidIndex(a, left, right);
    Swap(&a[left],&a[mid]);
    // 这里的key不是下标，是a[left]的值
    int key = a[left];

    while (left < right)
    {
        // 右边找小，找到后，将值给left，留下一个坑位
        while (left < right && a[right] >= key)
        {
            --right;
        }
        a[left] = a[right];
        // 左边找大，找到后，将值给right，留下一个坑位
        while (left < right && a[left] <= key)
        {
            ++left;
        }
        a[right] = a[left];
    }
    // 相遇后，将key给相遇的位置,left和right都可以
    a[left] = key;
    return left;
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