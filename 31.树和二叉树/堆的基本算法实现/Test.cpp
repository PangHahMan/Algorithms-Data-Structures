#include "Heap.h"

void test()
{
	Heap hp;
	HeapInit(&hp);
	int arr[10] = { 23,45,23,88,57,43,25,96,35,16 };
	HeapCreate(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	HeapPrint(&hp);
	HeapDestroy(&hp);
}

int main()
{
	test();
	return 0;
}