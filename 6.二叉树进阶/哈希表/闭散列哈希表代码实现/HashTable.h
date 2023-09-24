#pragma once
#include <iostream>
#include <vector>
using namespace std;
// 闭散列哈希表
enum State {
    EMPTY,// 哈希表位置为NULL
    EXITS,// 哈希表位置有值了
    DELETE// 哈希表位置为删除标志
};

template<class K, class V>
struct HashData {
    pair<K, V> _kv;
    State _state = EMPTY;//状态初始化为空
};

template<class K, class V>
class HashTable {
public:
    HashData<K, V> *Find(const K &key) {
        //哈希表大小为0，表示哈希表为空，返回nullptr
        if (this->_tables.size() == 0) {
            return nullptr;
        }

        //哈希函数
        size_t hashi = key % this->_tables.size();
        size_t i = 1;
        size_t index = hashi;// index是插入的位置
        // 当哈希状态为EXITS，说明表中位置已经有值，那么就继续查找
        while (this->_tables[index]._state != EMPTY) {
            // 当表中值跟key相等，并且状态为存在时才返回，因为可能值的状态被改为了delete说明刚刚被删除，不可以返回
            if (this->_tables[index]._kv.first == key && this->_tables[index]._state == EXITS) {
                return &this->_tables[index];
            }
            index = hashi + i;//线性探测
            //index = hashi + i * i;  //二次探测
            index %= this->_tables.size();// 防止index越界，绕回去
            i++;

            // 这里的_state可能都是存在或者删除，那么程序就可能陷入死循环，所以需要给定条件退出
            // 如果已经查找一圈，那么说明全是存在+删除
            if (index == hashi) {
                break;
            }
        }

        return nullptr;
    }
    bool Insert(const pair<K, V> &kv) {
        //1.查找值
        if (Find(kv.first)) {
            return false;
        }

        // 当我们的哈希表是空或者负载因子大于0.7的时候，我们需要给将哈希表增容
        // 负载因子 = 表中有效数据个数 / 空间的大小
        if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7) {
            //为空的时候，给初始10，负载因子大于0.7就扩容两倍
            size_t newsize = this->_tables.size() == 0 ? 10 : this->_tables.size() * 2;
            HashTable<K, V> newHashTable;// 重新创建一个HashTable类
            newHashTable._tables.resize(newsize);

            // 遍历旧表，重新映射到新表
            for (auto &data: this->_tables) {// data是_table中的类型，对应的HashData
                if (data._state == EXITS) {
                    newHashTable.Insert(data._kv);// 将旧的kv插入到新的类对象中
                }
            }

            //交换
            this->_tables.swap(newHashTable._tables);
        }

        //哈希函数
        size_t hashi = kv.first % this->_tables.size();

        // 线形探测
        size_t i = 1;
        size_t index = hashi;// index是最后要插入的位置
        // 当哈希状态为EXITS，说明表中位置已经有值，那么就继续查找
        while (this->_tables[index]._state == EXITS) {
            index = hashi + i;
            //index = hashi + i * i;  //二次线性探测
            index %= this->_tables.size();// 防止index越界，绕回去
            i++;
        }

        this->_tables[index]._kv = kv;
        this->_tables[index]._state = EXITS;
        this->_n++;// 存储的数据个数+1

        return true;
    }
    bool Erase(const K &key) {
        HashData<K, V> *ret = Find(key);
        if (ret) {
            ret->_state = DELETE;
            this->_n--;
            return true;
        } else {
            return false;
        }
    }

private:
    vector<HashData<K, V>> _tables;// 将Hash值存放在vector中
    size_t _n = 0;                 // 存储的数据个数
};