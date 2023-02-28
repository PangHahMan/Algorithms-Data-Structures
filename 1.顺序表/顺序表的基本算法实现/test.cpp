#include "SeqList.h"
// ˳���ĳ�ʼ��
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

// ˳��������
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->size = 0;
	ps->capacity = 0;
}

// ˳���Ĵ�ӡ
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// ����
void Check_Capacity(SeqList* ps)
{
	if (ps->capacity == ps->size)
	{
		// ����������ڴ�С˵��������Ҫ����   ���size��capacityΪ0��˵���ǳ�ʼ��״̬��Ĭ�ϸ�4���ֽڣ��������������
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		// �����ݵ�ָ��ŵ���ʱ������
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

// ˳����β��
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	/*
	assert(ps);
	Check_Capacity(ps);
	// β��-���뵽˳����е���һ��λ�ã��±�Ҳ����ps->size
	ps->a[ps->size] = x;
	ps->size++;
	*/
	SeqListInsert(ps, ps->size + 1, x);  //+1 �Ƕ�Ӧ�߼��±�
}

// ˳����ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	/*
	assert(ps);
	Check_Capacity(ps);
	// ͷ��-���뵽˳�����ʼ��λ�ã��±���0��������ҪŲ������˳���
	for (int i = ps->size; i >= 0; i--) // ����������Ų������һ��λ��
	{
		// size���±������λ�õ���һ��
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
	*/
	SeqListInsert(ps, 1, x);
}

// ˳����ͷɾ
void SeqListPopFront(SeqList* ps)
{
	/*
	assert(ps);
	assert(ps->size);
	// ��˳���г��˵�һ��λ�õ�����������ǰŲ��һ���±�
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
	*/
	SeqListErase(ps, 1);
}

// ˳����βɾ
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}

// ˳������
int SeqListFind(SeqList* ps, SLDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i + 1;  //i+1��Ӧ�߼��±�
		}
	}
	return -1;  //�Ҳ�������-1
}

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, int pos, SLDataType x)
{
	pos--; //pos��Ӧ�����±�
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	Check_Capacity(ps);
	//��pos������������Ų��һ��λ��
	for (int i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}

	ps->a[pos] = x;
	ps->size++;
}

//˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, int pos)
{
	pos--;  //���������±�
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	//��posλ�ÿ�ʼ���������ݶ���ǰŲ��һ��λ��
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}