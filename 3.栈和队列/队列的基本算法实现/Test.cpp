#include "Queue.h"
void test()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	QueuePush(&q, 7);
	QueuePush(&q, 8);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);

	QueuePrint(&q);
	QueueDestroy(&q);
}

int main()
{
	test();
	return 0;
}