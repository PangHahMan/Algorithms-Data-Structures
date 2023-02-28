#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// �鲢���� - �����������䣬���αȽ�ȡС��β��
// ��ô��֤ÿ�ζ�������ģ��ݹ鵽���������ڿ�ʼ���򣬵ݹ������ÿ�ξͶ��������
void _MergeSort(int *a, int left, int right, int *tmp)
{
    if (left >= right)
        return;

    // ����������
    int mid = (left + right) / 2;
    //[left, mid] [mid+1, right] �ݹ�������������
    // �ݹ�������
    _MergeSort(a, left, mid, tmp);
    // �ݹ�������
    _MergeSort(a, mid + 1, right, tmp);

    // ��ʼ�鲢
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
    // begin1<=end ˵��begin1��û�����꣬����ʣ�µ�
    while (begin1 <= end1)
    {
        tmp[i++] = a[begin1++];
    }

    while (begin2 <= end2)
    {
        tmp[i++] = a[begin2++];
    }
    // ��tmp���鸲�ǵ�a�����У��±��ÿ�ι鲢��left��ʼ
    // right-left ��С�꣬��������������Ҫ+1
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
    // ��ֵΪ�±�ֵ
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