#include <stdio.h>
// ����
void Swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// ���µ��� - ���
void AdjustDown(int *a, int n, int parent) {
    // ����Ǵ�ѣ����Ҹ��׵ĺ����еĴ�ģ�Ȼ���������
    // �ȼ��������Ǵ�ģ�������ǣ���������Ϊ�Һ����Ǵ��
    int child = parent * 2 + 1;
    // child��ֵ����Խ�磬����ѭ��������child < n
    while (child < n) {
        // �����������ĺ��ӣ�����Һ��Ӵ󣬾�++child��������������Ľڵ㣬ֻ�����ӣ�û���Һ��ӣ����Ի�Ҫ�����жϣ�����+1<n˵������һ���Һ���
        if (child + 1 < n && a[child] < a[child + 1]) {
            child++;
        }
        // 1.����С�ں��ӣ��������������µ���
        // 2.���״��ں��ӣ�����
        if (a[parent] < a[child]) {
            Swap(&a[parent], &a[child]);
            // ��������������parent������һ��λ�ÿ�ʼ���µ���
            parent = child;
            child = parent * 2 + 1;
        } else {
            break;
        }
    }
}

// ��������ж�����
void HeapSort(int *a, int n) {
    // ���ϵ������� -- N*logN
    /*for (int i = 1; i < n; ++i)
    {
    AdjustUp(a, i);
    }*/

    // ���µ������� - ��� O(N)    _
    for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
        AdjustDown(a, n, i);
    }

    int end = n - 1;
    while (end > 0) {
        // ��һ�������һ���������������һ����ʣ�µĽ��н��ѵ����������ĵ������Ѷ�
        Swap(&a[0], &a[end]);
        // endΪ���꣬����ȸ�����һ�������������end��ʣ��ĸ���
        AdjustDown(a, end, 0);
        end--;
    }
}

int main() {
    int arr[10] = {32, 43, 56, 76, 84, 12, 45, 67, 43, 37};
    HeapSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
}