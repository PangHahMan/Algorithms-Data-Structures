#include <stdio.h>
#include "Stack.h"
void Swap(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// ˫ָ��
int PartSort(int *a, int left, int right)
{
    // 1.cur�ұ�keyС���ҵ���ͣ���������һ��ʼcur�ͱ�keyС����ô++prev���±���ͬ���Ͳ�����
    // 2.++prev������prevλ�ú�curλ�õ�ֵ
    // 3.���cur����left��ʱ��ͣ������prev��key������key����������ȷ��λ��
    int key = left;
    int prev = left, cur = left + 1;
    while (cur <= right)
    {
        // cur�ұ�keyС��ֵ������++prev����curͬһ���꣬�͸�++prev����,
        if (a[cur] < a[key] && ++prev != cur)
            Swap(&a[cur], &a[prev]);

        cur++;
    }
    // ���key��prev����
    Swap(&a[key], &a[prev]);
    key = prev;
    return key;
}

// �������� �ǵݹ�ʵ�֣�left��right����С�꣬������
void QuickSortNonR(int *a, int left, int right)
{
    Stack st;
    StackInit(&st);
    // �������±���ջ
    StackPush(&st, left);
    StackPush(&st, right);
    while (!StackEmpty(&st))
    {
        // ջ��˳�����෴�ģ�������ȡ����right�±�
        int right = StackTop(&st);
        StackPop(&st);
        int left = StackTop(&st);
        StackPop(&st);

        // ��key
        int key = PartSort(a, left, right);
        // ����󣬽�key���������������ֱ���ջ
        // ���left<key˵��key�������仹��ֵ����Ҫpush������
        if (left < key)
        {
            StackPush(&st, left);
            StackPush(&st, key - 1);
        }
        // ���key<right ˵��key�������仹��ֵ����Ҫpush������
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