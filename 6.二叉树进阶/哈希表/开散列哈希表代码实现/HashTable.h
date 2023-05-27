#pragma once

#include<iostream>
#include<vector>

using namespace std;

template<class K, class V>
struct HashNode {
    HashNode<K, V>* _next;
    pair<K, V> _kv;

    HashNode(const pair<K, V>& kv) {
        this->_kv = kv;
        this->_next = nullptr;
    }
};

template<class K, class V>
class HashTable {
    typedef HashNode<K, V> Node;
public:
    ~HashTable()
    {
        for (auto& cur : this->_tables) {
            while (cur) {
                Node* next = cur->_next;
                delete cur;
                cur = next;
            }
            cur = nullptr;
        }
    }

    Node* Find(const K& key) {
        if (this->_tables.size() == 0) {
            return nullptr;
        }

        size_t hashi = key % this->_tables.size();
        Node* cur = this->_tables[hashi];
        while (cur) {
            if (cur->_kv.first == key) {
                return cur;
            }
            cur = cur->_next;
        }
        return nullptr;
    }

    bool Erase(const K& key) {
        size_t hashi = key % this->_tables.size();
        Node* prev = nullptr;
        Node* cur = this->_tables[hashi];
        while (cur) {
            if (cur->_kv.first == key) {
                if (prev == nullptr) {
                    this->_tables[hashi] = cur->_next;
                }
                else {
                    prev->_next = cur->_next;
                }
                delete cur;
                return true;
            }
            else {
                prev = cur;
                cur = cur->_next;
            }
        }
        return false;
    }

    bool Insert(const pair<K, V>& kv) {
        //已经有这个数，就不用插入了
        if (Find(kv.first)) {
            return false;
        }

        //负载因子 == 1时扩容
        if (this->n == this->_tables.size()) {
            size_t newsize = this->_tables.size() == 0 ? 10 : this->_tables.size() * 2;
            vector<Node*> newtables(newsize);
            for (auto& cur : this->_tables) {   //cur是Node*
                while (cur) {
                    //保存下一个
                    Node* next = cur->_next;
                    //头插到新表
                    size_t hashi = kv.first % newtables.size();
                    cur->_next = newtables[hashi];
                    newtables[hashi] = cur;

                    cur = next;
                }
            }
            _tables.swap(newtables);
        }
        size_t hashi = kv.first % this->_tables.size();
        //头插
        Node* newnode = new Node(kv);
        newnode->_next = _tables[hashi];
        _tables[hashi] = newnode;
        this->n++;

        return true;
    }

private:
    vector<Node*> _tables;
    size_t n = 0;  //存储有效数据的个数
};