#include "bitset.h"
#include <cstdlib>
#include <ctime>
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

    bitset<-1> bs;//会开512MB的空间，整型的最大值
                  //bitset<0xFFFFFFFF> bs;
}

void test_bitset3() {
    int a[] = {3, 45, 53, 32, 32, 43, 3, 2, 5, 2, 32, 55, 5, 53, 43, 9, 8, 7, 8};
    twobitset<100> bs;
    for (auto e: a) {
        bs.set(e);//7 9 45 55
    }

    bs.Print();
}

void test_bloomfilter1() {
    BloomFilter<100> bs;
    bs.set("sort");
    bs.set("bloom");
    bs.set("hello world hello bit");
    bs.set("test");
    bs.set("etst");
    bs.set("estt");

    cout << bs.test("sort") << endl;                 //1
    cout << bs.test("bloom") << endl;                //1
    cout << bs.test("hello world hello bit") << endl;//1
    cout << bs.test("etst") << endl;                 //1
    cout << bs.test("test") << endl;                 //1
    cout << bs.test("estt") << endl;                 //1

    cout << bs.test("ssort") << endl;//0
    cout << bs.test("tors") << endl; //0
    cout << bs.test("ttes") << endl; //0
}

void test_bloomfilter2() {
    srand(time(0));
    const size_t N = 10000;
    BloomFilter<N> bf;

    std::vector<std::string> v1;
    std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";

    for (size_t i = 0; i < N; ++i) {
        v1.push_back(url + std::to_string(i));
    }

    for (auto &str: v1) {
        bf.set(str);
    }

    // v2跟v1是相似字符串集，但是不一样
    std::vector<std::string> v2;
    for (size_t i = 0; i < N; ++i) {
        std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
        url += std::to_string(999999 + i);
        v2.push_back(url);
    }

    size_t n2 = 0;
    for (auto &str: v2) {
        if (bf.test(str)) {
            ++n2;
        }
    }
    cout << "相似字符误判率：" << (double) n2 / (double) N << endl;

    // 不相似字符串集
    std::vector<std::string> v3;
    for (size_t i = 0; i < N; ++i) {
        string url = "zhihu.com";
        //string url = "https://www.cctalk.com/m/statistics/live/16845432622875";
        url += std::to_string(i + rand());
        v3.push_back(url);
    }

    size_t n3 = 0;
    for (auto &str: v3) {
        if (bf.test(str)) {
            ++n3;
        }
    }
    cout << "不相似字符误判率：" << (double) n3 / (double) N << endl;
}

int main() {
    test_bloomfilter2();
    return 0;
}