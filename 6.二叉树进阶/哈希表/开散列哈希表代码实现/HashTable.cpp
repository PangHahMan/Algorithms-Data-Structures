#include"HashTable.h"
void TestHashTable1() {
    int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
    HashTable<int, int> ht;
    for (auto e : a)
    {
        ht.Insert(make_pair(e, e));
    }

    ht.Insert(make_pair(15, 15));
    ht.Insert(make_pair(25, 25));
    ht.Insert(make_pair(35, 35));
    ht.Insert(make_pair(45, 45));
}

void TestHashTable2()
{
    int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
    HashTable<int, int> ht;
    for (auto e : a)
    {
        ht.Insert(make_pair(e, e));
    }

    ht.Erase(12);
    ht.Erase(3);
    ht.Erase(33);
}

int main() {
    TestHashTable1();
    return 0;
}


