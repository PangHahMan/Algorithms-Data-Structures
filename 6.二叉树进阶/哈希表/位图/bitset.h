#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;


template<size_t N>//非类型模板参数 N，它的类型是 size_t
class bitset {
public:
    bitset() {
        _bits.resize(N / 8 + 1, 0);
    }

    void set(size_t x) {
        size_t i = x / 8;//计算x映射的位在第i个char数组的位置
        size_t j = x % 8;//计算x映射的位在这个char的第j个比特位

        _bits[i] |= (1 << j);//将比特位设置为1
    }

    void reset(size_t x) {
        size_t i = x / 8;//计算x映射的位在第i个char数组的位置
        size_t j = x % 8;//计算x映射的位在这个char的第j个比特位

        _bits[i] &= ~(1 << j);//将比特位置0
    }

    bool test(size_t x) {
        size_t i = x / 8;
        size_t j = x % 8;

        return _bits[i] & (1 << j);//测试比特位是否为1
    }

private:
    vector<char> _bits;//位图底层结构
};


//给定100亿个整数，设计只出现一次的整数？
//思路：设计两个位图，第一个位图出现为1，再次出现就将第二个位图设为1，最后判断第二个位图为0就是出现一次
template<size_t N>
class twobitset {
public:
    void set(size_t x) {
        //新插入的值放在bs2中
        if (_bs1.test(x) == false && _bs2.test(x) == false) {
            _bs2.set(x);
        }
        //如果在插入，就将bs2reset，插入到bs1中，那么只要判断ps2是否为真即是出现一次的
        else if (_bs1.test(x) == false && _bs2.test(x) == true) {
            _bs1.set(x);
            _bs2.reset(x);
        }
    }

    void Print() {
        for (size_t i = 0; i < N; ++i) {
            if (_bs2.test(i)) {
                cout << i << endl;
            }
        }
    }

private:
    bitset<N> _bs1;
    bitset<N> _bs2;
};


#pragma once

template<size_t N>
class BloomFilter {
public:

private:
};