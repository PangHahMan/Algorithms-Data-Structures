#include "SeqList.h"
// 顺序表的初始化
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

// 顺序表的销毁
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->size = 0;
	ps->capacity = 0;
}

// 顺序表的打印
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// 扩容
void Check_Capacity(SeqList* ps)
{
	if (ps->capacity == ps->size)
	{
		// 如果容量等于大小说明满了需要扩容   如果size和capacity为0，说明是初始化状态，默认给4个字节，否则就扩容两倍
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		// 将扩容的指针放到临时变量中
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
	}
}

// 顺序表的尾插
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	/*
	assert(ps);
	Check_Capacity(ps);
	// 尾插-插入到顺序表中的下一个位置，下标也就是ps->size
	ps->a[ps->size] = x;
	ps->size++;
	*/
	SeqListInsert(ps, ps->size + 1, x);  //+1 是对应逻辑下标
}

// 顺序表的头插
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	/*
	assert(ps);
	Check_Capacity(ps);
	// 头插-插入到顺序表的最开始的位置，下标是0，但是需要挪动整个顺序表
	for (int i = ps->size; i >= 0; i--) // 将所有数据挪动到下一个位置
	{
		// size的下标是最后位置的下一个
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
	*/
	SeqListInsert(ps, 1, x);
}

// 顺序表的头删
void SeqListPopFront(SeqList* ps)
{
	/*
	assert(ps);
	assert(ps->size);
	// 将顺序中除了第一个位置的所有数据向前挪动一个下标
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
	*/
	SeqListErase(ps, 1);
}

// 顺序表的尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i + 1;  //i+1对应逻辑下标
		}
	}
	return -1;  //找不到返回-1
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDataType x)
{
	pos--; //pos对应数组下标
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	Check_Capacity(ps);
	//将pos后面的数据向后挪动一个位置
	for (int i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}

	ps->a[pos] = x;
	ps->size++;
}

//顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos)
{
	pos--;  //对其数组下标
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	//从pos位置开始，后面数据都向前挪动一个位置
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}