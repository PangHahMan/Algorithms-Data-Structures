#pragma once
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

        return _bits[i] % (1 << j);//测试比特位是否为1
    }

private:
    vector<char> _bits;//位图底层结构
};
