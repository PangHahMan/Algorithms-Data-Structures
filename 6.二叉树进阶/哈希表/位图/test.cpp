#include "bitset.h"
#include <iostream>
using namespace std;
void test_bitset1() {
    bitset<100> bs;
    bs.set(10);
    bs.set(11);
    bs.set(15);

    cout << bs.test(10) << endl;//1
    cout << bs.test(15) << endl;//1

    bs.reset(10);

    cout << bs.test(10) << endl;//0
    cout << bs.test(15) << endl;//1

    bs.reset(10);
    bs.reset(15);

    cout << bs.test(10) << endl;//0
    cout << bs.test(10) << endl;//0
}

//如何开数据量很大的空间
void test_bitset2() {
    
    bitset<-1> bs;   //会开512MB的空间，整型的最大值
    //bitset<0xFFFFFFFF> bs;

}

void test_bitset3(){
    int a[] = { 3, 45, 53, 32, 32, 43, 3, 2, 5, 2, 32, 55, 5, 53,43,9,8,7,8 };
	twobitset<100> bs;
	for (auto e : a)
	{
		bs.set(e);    //7 9 45 55
	}

    bs.Print();
	
}

int main() {
    test_bitset3();
    return 0;
}