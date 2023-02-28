#include <stdio.h>

// ��������
// ÿ����һ��ֵ���ͺ�ǰ����������Ƚϣ�Ȼ��ǰ�������Ų�������棬ֱ������
void InSertSort(int *arr, int n)
{
    // ����n������end��Ϊ�±꿪ʼ��tmp��end+1  �����±�n-1
    for (int i = 0; i < n - 1; i++)
    {
        int end = i;
        // tmp�ݴ�ֵ��ֱ���ҵ�����󣬲������һ��ֵ
        int tmp = arr[end + 1];
        while (end >= 0)
        {
            // ����������Ų�����ݣ�ֱ����������
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
        // �������һ��ֵ��ǰ��end-- ��endΪ0ʱ��end��Խ�磬����end+1
        arr[end+1] = tmp;
    }
}

int main()
{
    int arr[] = {11, 64, 12, 85, 23, 46, 89, 34, 35, 78};
    InSertSort(arr, sizeof(arr) / sizeof(int));

    for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}