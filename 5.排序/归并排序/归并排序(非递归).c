#include <stdio.h>
#include <stdlib.h>
void MergeSortNonR(int *a, int n) {
    int *tmp = (int *) malloc(sizeof(int) * n);
    if (tmp == NULL) {
        perror("malloc fail");
        exit(-1);
    }

    // �鲢ÿ�����ݸ�������1��ʼ����Ϊ1����Ϊ������ģ�����ֱ�ӹ鲢
    int rangeN = 1;
    while (rangeN < n) {
        for (int i = 0; i < n; i += 2 * rangeN) {
            //[begin1��end1][begin2��end2]
            // ��ʼ���±�ֵ
            int begin1 = i, end1 = i + rangeN - 1;
            int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;
            int j = i;

            // end1 begin2 end2 ����Խ��
            // �������� -> �������� �鲢�������忽�� or �鲢ÿ�鿽��
            if (end1 >= n) {
                end1 = n - 1;
                // ����һ�������ڵ�����
                begin2 = n;
                end2 = n - 1;
            } else if (begin2 >= n) {
                // ���ò���������
                begin2 = n;
                end2 = n - 1;
            } else if (end2 >= n) {
                end2 = n - 1;
            }

            // ��ʼ�鲢
            while (begin1 <= end1 && begin2 <= end2) {
                if (a[begin1] <= a[begin2]) {
                    tmp[j++] = a[begin1++];
                } else {
                    tmp[j++] = a[begin2++];
                }
            }

            while (begin1 <= end1) {
                tmp[j++] = a[begin1++];
            }

            while (begin2 <= end2) {
                tmp[j++] = a[begin2++];
            }

            // �鲢һ���֣�����һ����
            memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
        }
        // Ҳ�������忽��
        //memcpy(a, tmp, sizeof(int) * n);
        rangeN *= 2;
    }

    free(tmp);
    tmp = NULL;
}

int main() {
    int arr[] = {21, 64, 12, 85, 23, 46, 89, 34, 35, 78};
    MergeSortNonR(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}