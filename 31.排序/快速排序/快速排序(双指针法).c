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

// ˫ָ��
int PartSort(int *a, int left, int right)
{
    // ��left��right�м�ֵ������ֳ������Ե�����
    int mid = GetMidIndex(a, left, right);
    Swap(&a[left], &a[mid]);

    // 1.cur�ұ�keyС���ҵ���ͣ���������һ��ʼcur�ͱ�keyС����ô++prev���±���ͬ���Ͳ�����
    // 2.++prev������prevλ�ú�curλ�õ�ֵ
    // 3.���cur����right��ʱ��ͣ������prev��key������key����������ȷ��λ��
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