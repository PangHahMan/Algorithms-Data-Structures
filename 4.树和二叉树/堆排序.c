#include <stdio.h>
// 交换
void Swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// 向下调整 - 大堆
void AdjustDown(int *a, int n, int parent) {
    // 如果是大堆，先找父亲的孩子中的大的，然后跟他交换
    // 先假设左孩子是大的，如果不是，重新设置为右孩子是大的
    int child = parent * 2 + 1;
    // child的值不会越界，所以循环条件是child < n
    while (child < n) {
        // 重新设置最大的孩子，如果右孩子大，就++child。特殊情况：最后的节点，只有左孩子，没有右孩子，所以还要加条判断，左孩子+1<n说明还有一个右孩子
        if (child + 1 < n && a[child] < a[child + 1]) {
            child++;
        }
        // 1.父亲小于孩子，交换，继续向下调整
        // 2.父亲大于孩子，跳出
        if (a[parent] < a[child]) {
            Swap(&a[parent], &a[child]);
            // 交换后，重新设置parent，找下一个位置开始向下调整
            parent = child;
            child = parent * 2 + 1;
        } else {
            break;
        }
    }
}

// 对数组进行堆排序
void HeapSort(int *a, int n) {
    // 向上调整建堆 -- N*logN
    /*for (int i = 1; i < n; ++i)
    {
    AdjustUp(a, i);
    }*/

    // 向下调整建堆 - 大堆 O(N)    _
    for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
        AdjustDown(a, n, i);
    }

    int end = n - 1;
    while (end > 0) {
        // 第一个和最后一个交换，除了最后一个，剩下的进行建堆调整，把最大的调整到堆顶
        Swap(&a[0], &a[end]);
        // end为坐标，坐标比个数多一个，所以下面的end是剩余的个数
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