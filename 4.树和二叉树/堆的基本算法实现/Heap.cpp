#include "Heap.h"

// 堆的初始化
void HeapInit(Heap *php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

// 堆的打印
void HeapPrint(Heap *php)
{
	assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

// 堆的销毁
void HeapDestroy(Heap *php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

// 向上调整 - 大堆
void AdjustUp(HPDataType *a, int child)
{
	// 1.找父亲
	int parent = (child - 1) / 2;
	// 2.跟父亲比大小，如果是大堆，知道父亲大于孩子循环结束，如果一直小于孩子，一直交换，然后循环结束条件是child==0
	while (child > 0)
	{
		// 孩子大于父亲则交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// 向下调整 - 大堆
void AdjustDown(HPDataType *a, int n, int parent)
{
	// 如果是大堆，先找父亲的孩子中的大的，然后跟他交换
	// 先假设左孩子是大的，如果不是，重新设置为右孩子是大的
	int child = parent * 2 + 1;
	// child的值不会越界，所以循环条件是child < n
	while (child < n)
	{
		// 重新设置最大的孩子，如果右孩子大，就++child。特殊情况：最后的节点，只有左孩子，没有右孩子，所以还要加条判断，左孩子+1<n说明还有一个右孩子
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		// 1.父亲小于孩子，交换，继续向下调整
		// 2.父亲大于孩子，跳出
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			// 交换后，重新设置parent，找下一个位置开始向下调整
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆的插入
void HeapPush(Heap *php, HPDataType x)
{
	assert(php);
	// 内存满了，扩容
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType *tmp = (HPDataType *)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	// 插入
	php->a[php->size] = x;
	php->size++;
	// 插入完，开始向上调整建堆
	// 将数组和child的位置传过去
	AdjustUp(php->a, php->size - 1);
}

// 堆的删除
void HeapPop(Heap *php)
{
	assert(php);
	assert(php->size > 0);

	// 堆的删除，因为不能破坏堆的结构，所以将堆顶，和堆底最后一个数据交换，然后删除堆底，堆顶再向下调整，保持堆的结构
	// 1.交换堆顶和堆底
	Swap(&php->a[0], &php->a[php->size - 1]);
	// 2.删除堆底
	php->size--;
	// 3.向下调整
	AdjustDown(php->a, php->size, 0);
}

// 取堆顶
HPDataType HeapTop(Heap *php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

// 求堆的长度
size_t HeapSize(Heap *php)
{
	assert(php);

	return php->size;
}

// 堆的判空
bool HeapEmpty(Heap *php)
{
	assert(php);

	return php->size == 0;
}

// 交换
void Swap(HPDataType *p1, HPDataType *p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 堆的创建 - 建堆算法
void HeapCreate(Heap *php, HPDataType *a, int n)
{
	assert(php);
	php->a = (HPDataType *)realloc(php->a, sizeof(HPDataType) * n);
	if (php->a == NULL)
	{
		perror("realloc fail");
		exit(-1);
	}
	// 内存复制  数组复制到php->a中
	memcpy(php->a, a, sizeof(HPDataType) * n);
	php->size = php->capacity = n;
	// 建堆算法 - 从最后一个叶子节点的父亲节点开始向下调整，然后从父亲节点的前所有节点都向下调整一次
	// 最后节点的父亲的坐标是(n-1-1)/2  n-1因为n是节点个数，坐标从0开始
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->a, n, i);
	}
}