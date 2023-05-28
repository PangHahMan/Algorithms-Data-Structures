#include"HashTable.h"
void TestHashTable1() {
    int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
    HashTable<int, int> ht;
    for (auto e : a){
        ht.Insert(make_pair(e, e));
    }

    ht.Insert(make_pair(15, 15));
    ht.Insert(make_pair(25, 25));
    ht.Insert(make_pair(35, 35));
    ht.Insert(make_pair(45, 45));
}

void TestHashTable2(){
    int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
    HashTable<int, int> ht;
    for (auto e : a){
        ht.Insert(make_pair(e, e));
    }

    ht.Erase(12);
    ht.Erase(3);
    ht.Erase(33);

}

//struct HashStr {
//    size_t operator()(const string& s) {
//        size_t hash = 0;
//        for (auto ch : s) {
//            hash += ch;
//            hash *= 31;
//        }
//        return hash;
//    }
//};

void TestHashTable3() {
    HashTable<string, string> ht;
    ht.Insert(make_pair("sort", "排序"));
    ht.Insert(make_pair("string", "字符串"));
    ht.Insert(make_pair("left", "左边"));
    ht.Insert(make_pair("right", "右边"));
    ht.Insert(make_pair("", "右边"));


    /*cout << hashstr("abcd") << endl;
    cout << hashstr("bcda") << endl;
    cout << hashstr("aadd") << endl;
    cout << hashstr("eat") << endl;
    cout << hashstr("ate") << endl;*/
}

void TestHashTable4()
{
    size_t N = 100000;
    HashTable<int, int> ht;
    srand(time(0));
    for (size_t i = 0; i < N; ++i)
    {
        size_t x = rand() + i;
        ht.Insert(make_pair(x, x));
    }
    //ht.MaxBucketSize();
    cout << ht.MaxBucketSize() << endl;
}

int main() {
    TestHashTable4();
    return 0;
}


