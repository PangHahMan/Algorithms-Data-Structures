#include "BSTree.h"
#include <utility>
#include <cstdlib>
#include <ctime>
using namespace std;
void Test_RBTree1()
{
	// int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 16, 3, 7, 11, 9, 26, 18, 14, 15};
	RBTree<int, int> t1{};
	for (auto e : a)
	{
		/*	if (e == 14)
		{
		int x = 0;
		}*/

		t1.Insert(make_pair(e, e));
		// cout << e << "插入：" << t1.IsBalance() << endl;
	}

	t1.InOrder();
	cout << t1.IsBalance() << endl;
}

void Test_RBTree2()
{
	srand(time(nullptr));
	const size_t N = 1000000;
	RBTree<int, int> t{};
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.Insert(make_pair(x, x));
		// cout << t.IsBalance() << endl;
	}

	// t.InOrder();

	cout << t.IsBalance() << endl;
	cout << t.Height() << endl;
}

int main()
{
	Test_RBTree2();
	return 0;
}