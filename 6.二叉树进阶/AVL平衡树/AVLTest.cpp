#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "AVLTree.h"
using namespace std;

void Test_AVLTree1()
{
	int a[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
	AVLTree<int, int> t1;
	for (auto e : a)
	{
		// 条件断点
		if (e == 14)
		{
			int x = 0; // 不能为空语句
		}
		t1.Insert(make_pair(e, e));
		cout << e << "插入:" << t1.IsBalanace() << endl; // 为了测试插入哪个异常所以加上了打印
		// 屏蔽右左旋转的平衡因子更新观察现象
	}
	t1.InOrder();
	cout << t1.IsBalanace() << endl;
};

void Test_AVLTree2()
{
	srand(time(0));
	const size_t n = 100000;
	AVLTree<int, int> t;
	for (size_t i = 0; i < n; i++)
	{
		size_t x = rand();
		t.Insert(make_pair(x, x));
	}
	// t.InOrder();
	cout << t.IsBalanace() << endl;
}

int main()
{
	Test_AVLTree2();
	return 0;
}