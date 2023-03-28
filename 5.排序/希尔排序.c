#include <stdio.h>

void ShellSort(int *arr, int n)
{
    // gapΪ�����������Ĳ�������Ƚ���һ��һ���Ƚ�����ϣ������������gap�����бȽ����򣬱Ƚ�����ڽ������һ�β�������Ҳ����gap=1ʱ
    int gap = n;
    while (gap > 1)
    {
        // ��֤���һ��һ����1,1����һ��ֱ������
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