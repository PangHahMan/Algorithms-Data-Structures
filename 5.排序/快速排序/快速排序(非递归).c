#include <stdio.h>
#include "Stack.h"
void Swap(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// 双指针
int PartSort(int *a, int left, int right)
{
    // 1.cur找比key小，找到后停下来，如果一开始cur就比key小，那么++prev后，下标相同，就不交换
    // 2.++prev，交换prev位置和cur位置的值
    // 3.最后当cur大于left的时候，停下来，prev和key交换，key就来到了正确的位置
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

// 快速排序 非递归实现，left，right都是小标，闭区间
void QuickSortNonR(int *a, int left, int right)
{
    Stack st;
    StackInit(&st);
    // 将左右下标入栈
    StackPush(&st, left);
    StackPush(&st, right);
    while (!StackEmpty(&st))
    {
        // 栈的顺序是相反的，所以先取的是right下标
        int right = StackTop(&st);
        StackPop(&st);
        int left = StackTop(&st);
        StackPop(&st);

        // 找key
        int key = PartSort(a, left, right);
        // 找完后，将key的左区间和右区间分别入栈
        // 如果left<key说明key的左区间还有值，需要push左区间
        if (left < key)
        {
            StackPush(&st, left);
            StackPush(&st, key - 1);
        }
        // 如果key<right 说明key的右区间还有值，需要push右区间
        if (key < right)
        {
            StackPush(&st, key + 1);
            StackPush(&st, right);
        }
    }
    StackDestroy(&st);
}

int main()
{
    int arr[] = {11, 64, 12, 85, 23, 46, 89, 34, 35, 78};
    QuickSortNonR(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}