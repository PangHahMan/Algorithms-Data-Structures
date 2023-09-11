//交换函数
void Swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
//堆的向下调整（小堆）
void AdjustDown(int *a, int n, int parent) {
    //child记录左右孩子中值较小的孩子的下标
    int child = 2 * parent + 1;//先默认其左孩子的值较小
    while (child < n) {
        if (child + 1 < n && a[child + 1] < a[child]) {//右孩子存在并且右孩子比左孩子还小
            child++;                                   //较小的孩子改为右孩子
        }
        if (a[child] < a[parent]) {//左右孩子中较小孩子的值比父结点还小
            //将父结点与较小的子结点交换
            Swap(&a[child], &a[parent]);
            //继续向下进行调整
            parent = child;
            child = 2 * parent + 1;
        } else {//已成堆
            break;
        }
    }
}

int *getLeastNumbers(int *arr, int arrSize, int k, int *returnSize) {
    *returnSize = k;
    if (k == 0)
        return NULL;
    //用数组的前K个数建小堆
    int i = 0;
    int *retArr = (int *) malloc(sizeof(int) * k);
    for (i = 0; i < k; i++) {
        retArr[i] = arr[i];
    }
    for (i = (k - 1 - 1) / 2; i >= 0; i--) {
        AdjustDown(retArr, k, i);
    }
    //剩下的N-k个数依次与堆顶数据比较
    for (i = k; i < arrSize; i++) {
        if (arr[i] > retArr[0]) {
            retArr[0] = arr[i];//堆顶数据替换
        }
        AdjustDown(retArr, k, 0);//进行一次向下调整
    }
    return retArr;//返回最大的k个数
}
