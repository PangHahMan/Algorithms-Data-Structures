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

// ����������Ż�(����ȡ��)
// ���һ�ߵ�����ǳ��Ķ࣬��ô�ݹ�Ķ������ṹ�Ĳ����ͻ�������ôЧ�ʾͻ��ͣ����Բ�������ȡ�У����м�ֵ����key���������Եȵ�����
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

// ��������hoare�汾
// һ������ �����key���ұ����ߣ��ұ��ҵ���keyС��ͣס��������ұ�key��ģ�Ȼ�󽻻�����������key����
// ��������key���ұ����ߣ�����ұ���key���������
// �����key���ұ����ߡ���֤����λ�ã���keyҪС
// 1���������ұ�ͣס�ģ���������ұߣ�����λ�þ����ұ�ͣס��λ��
// 2�����������ͣס�ģ��ұ�������ߣ�����λ�þ������ͣס��λ��
// ����������߱�keyС���ұ߱�key��
// 1���ָ���������䣬�������keyС���������key��
// 2��key�Ѿ��䵽��������ȷλ��(����������λ��)ʣ�µ�������� ������ĵݹ�����������ĵݹ�������ô�����OK��
int PartSort(int *a, int left, int right)
{
    int mid = GetMidIndex(a, left, right);
    Swap(&a[left], &a[mid]);

    int key = left;
    // ��left<right ��ʼ��
    while (left < right)
    {
        // �ұ����ߣ���С
        // ����left<right ����Ϊ������a[right]һֱ��a[key]����ôrightһֱ�����ȥ
        while (left < right && a[right] >= a[key])
        {
            --right;
        }
        // ������ߣ��Ҵ�
        while (left < right && a[left] <= a[key])
        {
            ++left;
        }

        Swap(&a[left], &a[right]);
    }
    // ���������λ�ú�key������left��right������
    Swap(&a[left], &a[key]);
    key = left;
    return key;
}

// �����left��right��Ϊ�±�
void QuickSort(int *a, int left, int right)
{
    // ��������ֻ��һ������ʱ�򣬴��Σ�left, key - 1  left=0��key=-1  left>right
    // ��������ֻ��һ������ʱ�򣬴��Σ�key + 1, right left=1��right = 0
    // ����һ�ֿ���һ��ʼ��һ����,left��right���
    if (left >= right)
    {
        return;
    }

    // С�����Ż������ٵݹ����
    if ((right - left) < 15)
    {
        // a+left ��Ϊ�ݹ�Ĳ��������������Ƕ�̬�ģ���ߵ��±��ǲ�ȷ����
        InSertSort(a + left, right - left + 1);
    }
    else
    {
        int key = PartSort(a, left, right);
        // ���鱻����Ϊ��������left - key - right
        // ������Ϊleft - key-1�� ������Ϊkey+1 - right
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