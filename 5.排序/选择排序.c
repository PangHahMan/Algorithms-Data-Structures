#include <stdio.h>

void Swap(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// ѡ������ - û�Ż�

/*
void SelectSort(int *arr, int n)
{
    //�ӵ�i������ʼ���Һ����������������С������Ȼ��͵�һ��������
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                // ����min������
                min = j;
            }
        }
        Swap(&arr[min],&arr[i]);
    }
}
*/

// ѡ������ - �Ż�
void SelectSort(int *arr, int n)
{
    // ��¼���ҵ��±꣬��С�ķŵ�left�±�λ�ã����ķŵ�right��λ��
    int left = 0, right = n - 1;
    // ��left<right����
    while (left < right)
    {
        int min = left, max = left;
        // ��ʣ�µ�ȥ����С����������
        for (int i = left + 1; i <= right; i++)
        {
            // ����С�������±�
            if (arr[i] < arr[min])
            {
                min = i;
            }
            // �����������±�
            if (arr[i] > arr[max])
            {
                max = i;
            }
        }
        // ��С������left����
        Swap(&arr[min], &arr[left]);
        // ���max==left�Ļ����ո�left��min�����ˣ���ʱ��min�ͱ�������
        if (max == left)
        {
            max = min;
        }

        // ��������right����
        Swap(&arr[max], &arr[right]);
        left++;
        right--;
    }
}

int main()
{
    int arr[] = {11, 64, 12, 85, 23, 46, 89, 34, 35, 78};
    SelectSort(arr, sizeof(arr) / sizeof(int));
    for (size_t i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}