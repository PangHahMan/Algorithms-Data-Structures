#include <stdio.h>
#include <stdlib.h>
// ʱ�临�Ӷ�0(N+range),�ռ临�Ӷ�O(range)
// �㷨��Ч�ʺܸߣ����о����ԣ�ֻ����������ֵ�������range���󣬿ռ临�ӶȾͱȽϸ�
void CountSort(int *a, int n)
{
    int max = a[0], min = a[0];
    // �ҳ����ĺ���С�ģ������Χ
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];

        if (a[i] < min)
            min = a[i];
    }
    // ��Χ+1  ������Χ���ռ�
    int range = max - min + 1;
    int *tmp = (int *)calloc(range, sizeof(int));
    if (tmp == NULL)
    {
        perror("calloc fail");
        exit(-1);
    }
    // ͳ�ƴ���
    for (int i = 0; i < n; i++)
    {
        // ��tmp�������a[i]�����ּ���
        tmp[a[i] - min]++;
    }

    // ���� - ��tmp�����е������ǵ�a������
    int k = 0;
    for (int j = 0; j < range; j++)
    {
        if (tmp[j] != 0)
        {
            while (tmp[j]--)
            {
                // a[k]��ֵ����tmp�����±������С�ķ�Χ��ֵ
                a[k++] = j + min;
            }
        }
    }
    free(tmp);
}

int main()
{
    int arr[] = {11, 64, 12, 85, 23, 46, 89, 34, 35, 78};
    CountSort(arr, sizeof(arr) / sizeof(int));
    for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}