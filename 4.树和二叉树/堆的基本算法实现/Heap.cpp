#include "Heap.h"

// �ѵĳ�ʼ��
void HeapInit(Heap *php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

// �ѵĴ�ӡ
void HeapPrint(Heap *php)
{
	assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

// �ѵ�����
void HeapDestroy(Heap *php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

// ���ϵ��� - ���
void AdjustUp(HPDataType *a, int child)
{
	// 1.�Ҹ���
	int parent = (child - 1) / 2;
	// 2.�����ױȴ�С������Ǵ�ѣ�֪�����״��ں���ѭ�����������һֱС�ں��ӣ�һֱ������Ȼ��ѭ������������child==0
	while (child > 0)
	{
		// ���Ӵ��ڸ����򽻻�
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

// ���µ��� - ���
void AdjustDown(HPDataType *a, int n, int parent)
{
	// ����Ǵ�ѣ����Ҹ��׵ĺ����еĴ�ģ�Ȼ���������
	// �ȼ��������Ǵ�ģ�������ǣ���������Ϊ�Һ����Ǵ��
	int child = parent * 2 + 1;
	// child��ֵ����Խ�磬����ѭ��������child < n
	while (child < n)
	{
		// �����������ĺ��ӣ�����Һ��Ӵ󣬾�++child��������������Ľڵ㣬ֻ�����ӣ�û���Һ��ӣ����Ի�Ҫ�����жϣ�����+1<n˵������һ���Һ���
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		// 1.����С�ں��ӣ��������������µ���
		// 2.���״��ں��ӣ�����
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			// ��������������parent������һ��λ�ÿ�ʼ���µ���
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// �ѵĲ���
void HeapPush(Heap *php, HPDataType x)
{
	assert(php);
	// �ڴ����ˣ�����
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
	// ����
	php->a[php->size] = x;
	php->size++;
	// �����꣬��ʼ���ϵ�������
	// �������child��λ�ô���ȥ
	AdjustUp(php->a, php->size - 1);
}

// �ѵ�ɾ��
void HeapPop(Heap *php)
{
	assert(php);
	assert(php->size > 0);

	// �ѵ�ɾ������Ϊ�����ƻ��ѵĽṹ�����Խ��Ѷ����Ͷѵ����һ�����ݽ�����Ȼ��ɾ���ѵף��Ѷ������µ��������ֶѵĽṹ
	// 1.�����Ѷ��Ͷѵ�
	Swap(&php->a[0], &php->a[php->size - 1]);
	// 2.ɾ���ѵ�
	php->size--;
	// 3.���µ���
	AdjustDown(php->a, php->size, 0);
}

// ȡ�Ѷ�
HPDataType HeapTop(Heap *php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

// ��ѵĳ���
size_t HeapSize(Heap *php)
{
	assert(php);

	return php->size;
}

// �ѵ��п�
bool HeapEmpty(Heap *php)
{
	assert(php);

	return php->size == 0;
}

// ����
void Swap(HPDataType *p1, HPDataType *p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// �ѵĴ��� - �����㷨
void HeapCreate(Heap *php, HPDataType *a, int n)
{
	assert(php);
	php->a = (HPDataType *)realloc(php->a, sizeof(HPDataType) * n);
	if (php->a == NULL)
	{
		perror("realloc fail");
		exit(-1);
	}
	// �ڴ渴��  ���鸴�Ƶ�php->a��
	memcpy(php->a, a, sizeof(HPDataType) * n);
	php->size = php->capacity = n;
	// �����㷨 - �����һ��Ҷ�ӽڵ�ĸ��׽ڵ㿪ʼ���µ�����Ȼ��Ӹ��׽ڵ��ǰ���нڵ㶼���µ���һ��
	// ���ڵ�ĸ��׵�������(n-1-1)/2  n-1��Ϊn�ǽڵ�����������0��ʼ
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->a, n, i);
	}
}