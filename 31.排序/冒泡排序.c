#include <stdio.h>
void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(int *arr, int n)
{
    // �Ա�n-1��
    for (int i = 0; i < n - 1; i++)
    {
        int exchange = 0;
        // ���򣬽�������ݣ��Ƚϣ�һֱ����������λ��(n-i-1)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]);
                exchange = 1;
            }
        }
        // һ��ð�ݹ����У�û�з���������˵���Ѿ������ˣ�����Ҫ�ٴ���
        if (exchange == 0)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {11, 64, 12, 85, 23, 46, 89, 34, 35, 78};
    BubbleSort(arr, sizeof(arr) / sizeof(int));
    for (size_t i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}