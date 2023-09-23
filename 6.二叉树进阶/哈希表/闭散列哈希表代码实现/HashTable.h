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
    bool Insert(const pair<K, V> &kv) {
        //1.查找值
        if (Find(kv.first)) {
            return false;
        }
        // 负载因子超过0.7就扩容：这是自己规定
        //        if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7) {   //这里因为是0.7是double，所以换了一种写法
        //            size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
        //            vector<HashData<K,V>> newtables(newsize);
        //            //遍历旧表，重新映射到新表
        //            size_t hashi = kv.first % newtables.size();
        //            for(auto& data:_tables){
        //                if(data._state == EXITS){
        //                    //重新算在新表的位置
        //                    size_t i = 1;
        //                    size_t index = hashi;
        //                    while (newtables[index]._state == EXITS) {
        //                        index = hashi + i;
        //                        index %= newtables.size();   //防止index越界，绕回去
        //                        i++;
        //                    }
        //
        //                    newtables[index]._kv = kv;
        //                    newtables[index]._state = EXITS;
        //                }
        //            }
        //            _tables.swap(newtables);  //交换指针
        //        }

        // 修改上述扩容代码，使之不冗余
        // 负载因子 = 表中有效数据个数 / 空间的大小
        if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7) {
            //扩容两倍
            size_t newsize = this->_tables.size() == 0 ? 10 : this->_tables.size() * 2;
            HashTable<K, V> newHashTable;// 重新创建一个HashTable类
            newHashTable._tables.resize(newsize);

            // 遍历旧表，重新映射到新表
            for (auto &data: this->_tables) {// data是_table中的类型，对应的HashData
                if (data._state == EXITS) {
                    newHashTable.Insert(data._kv);// 将旧的kv插入到新的类对象中
                }
            }

            this->_tables.swap(newHashTable._tables);
        }

        size_t hashi = kv.first % this->_tables.size();

        // 线形探测
        size_t i = 1;
        size_t index = hashi;// index是最后要插入的位置
        // 当哈希状态为EXITS，说明表中位置已经有值，那么就继续查找
        while (this->_tables[index]._state == EXITS) {
            index = hashi + i;
            index %= this->_tables.size();// 防止index越界，绕回去
            i++;
        }

        this->_tables[index]._kv = kv;
        this->_tables[index]._state = EXITS;
        _n++;// 存储的数据个数+1

        return true;
    }

    HashData<K, V> *Find(const K &key) {
        if (this->_tables.size() == 0) {
            return nullptr;
        }

        size_t hashi = key % this->_tables.size();
        size_t i = 1;
        size_t index = hashi;// index是最后要插入的位置
        // 当哈希状态为EXITS，说明表中位置已经有值，那么就继续查找
        while (this->_tables[index]._state != EMPTY) {
            // 当表中值跟key相等，并且状态为存在时才返回，因为可能值的状态被改为了delete说明刚刚被删除，不可以返回
            if (this->_tables[index]._kv.first == key && this->_tables[index]._state == EXITS) {
                return &this->_tables[index];
            }
            index = hashi + i;
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