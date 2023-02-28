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

// 双指针
int PartSort(int *a, int left, int right)
{
    // 找left和right中间值，方便分出两个对等区间
    int mid = GetMidIndex(a, left, right);
    Swap(&a[left], &a[mid]);

    // 1.cur找比key小，找到后停下来，如果一开始cur就比key小，那么++prev后，下标相同，就不交换
    // 2.++prev，交换prev位置和cur位置的值
    // 3.最后当cur大于right的时候，停下来，prev和key交换，key就来到了正确的位置
    int key = left;
    int prev = left, cur = left + 1;
    while (cur <= right)
    {
        // cur找比key小的值，并且++prev不和cur同一坐标，就跟++prev交换,
        if (a[cur] < a[key] && ++prev != cur)
            Swap(&a[cur], &a[prev]);

        cur++;
    }
    // 最后key和prev交换
    Swap(&a[key], &a[prev]);
    key = prev;
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