#include "HashTable.h"


void TestHashTable1() {
    int a[] = {3, 33, 2, 13, 5, 12, 102};
    HashTable<int, int> ht;
    for(auto e:a){
        ht.Insert(make_pair(e,e));
    }

    ht.Insert(make_pair(15, 15));

    if (ht.Find(13))
    {
        cout << "13在" << endl;
    }
    else
    {
        cout << "13不在" << endl;
    }

    ht.Erase(13);

    if (ht.Find(13))
    {
        cout << "13在" << endl;
    }
    else
    {
        cout << "13不在" << endl;
    }

}

int main(){
    TestHashTable1();
}
