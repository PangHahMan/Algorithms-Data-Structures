#include"BSTree.h"

void test_BStree1()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> t;
	for (auto e :a)
	{
		t.Insert(e);
	}

	t.Erase(7);
	t.Erase(14);
	t.Erase(3);
	t.Erase(8);
	
	t.InOrder();
}

void test_BSTree2()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.InsertR(e);
	}

	t.EraseR(7);
	t.EraseR(14);
	t.EraseR(3);
	t.EraseR(8);
	t.EraseR(6);

	t.InOrder();
}

void test_BSTree3()
{
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	BSTree<int> t1;
	for (auto e : a)
	{
		t1.InsertR(e);
	}
	t1.InOrder();

	BSTree<int> t2(t1);
	t2.InOrder();
}

int main()
{
	test_BSTree2();
	return 0;
}