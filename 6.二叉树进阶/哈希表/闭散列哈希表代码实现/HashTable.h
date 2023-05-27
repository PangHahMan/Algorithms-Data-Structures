#pragma once

#include<vector>
#include<iostream>
using namespace std;
//��ɢ�й�ϣ��

enum State {
    EMPTY,   //��ϣ��λ��ΪNULL
    EXITS,   //��ϣ��λ����ֵ��
    DELETE   //��ϣ��λ��Ϊɾ����־
};

template<class K, class V>
struct HashData {
    pair <K, V> _kv;
    State _state = EMPTY;
};

template<class K, class V>
class HashTable {
public:
    bool Insert(const pair <K, V>& kv) {
        if(Find(kv.first)){
            return false;
        }
        //�������ӳ���0.7�����ݣ������Լ��涨
//        if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7) {   //������Ϊ��0.7��double�����Ի���һ��д��
//            size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
//            vector<HashData<K,V>> newtables(newsize);
//            //�����ɱ�����ӳ�䵽�±�
//            size_t hashi = kv.first % newtables.size();
//            for(auto& data:_tables){
//                if(data._state == EXITS){
//                    //���������±��λ��
//                    size_t i = 1;
//                    size_t index = hashi;
//                    while (newtables[index]._state == EXITS) {
//                        index = hashi + i;
//                        index %= newtables.size();   //��ֹindexԽ�磬�ƻ�ȥ
//                        i++;
//                    }
//
//                    newtables[index]._kv = kv;
//                    newtables[index]._state = EXITS;
//                }
//            }
//            _tables.swap(newtables);  //����ָ��
//        }

        //�޸��������ݴ��룬ʹ֮������
        if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7) {
            size_t newsize = this->_tables.size() == 0 ? 10 : this->_tables.size() * 2;
            HashTable<K, V> newHashTable;   //���´���һ��HashTable��
            newHashTable._tables.resize(newsize);

            // �����ɱ�����ӳ�䵽�±�
            for (auto& data : this->_tables) {   //data��_table�е����ͣ���Ӧ��HashData
                if (data._state == EXITS) {
                    newHashTable.Insert(data._kv);   //���ɵ�kv���뵽�µ��������
                }
            }

            this->_tables.swap(newHashTable._tables);
        }

        size_t hashi = kv.first % this->_tables.size();

        //����̽��
        size_t i = 1;
        size_t index = hashi;   //index�����Ҫ�����λ��
        //����ϣ״̬ΪEXITS��˵������λ���Ѿ���ֵ����ô�ͼ�������
        while (this->_tables[index]._state == EXITS) {
            index = hashi + i;
            index %= this->_tables.size();   //��ֹindexԽ�磬�ƻ�ȥ
            i++;
        }

        this->_tables[index]._kv = kv;
        this->_tables[index]._state = EXITS;
        _n++;   //�洢�����ݸ���+1

        return true;
    }

    HashData<K, V>* Find(const K& key) {
        if(this->_tables.size()==0){
            return nullptr;
        }

        size_t hashi = key % this->_tables.size();
        size_t i = 1;
        size_t index = hashi;   //index�����Ҫ�����λ��
        //����ϣ״̬ΪEXITS��˵������λ���Ѿ���ֵ����ô�ͼ�������
        while (this->_tables[index]._state != EMPTY) {
            //������ֵ��key��ȣ�����״̬Ϊ����ʱ�ŷ��أ���Ϊ����ֵ��״̬����Ϊ��delete˵���ոձ�ɾ���������Է���
            if(this->_tables[index]._kv.first == key
            && this->_tables[index]._state == EXITS){
                return &this->_tables[index];
            }
            index = hashi + i;
            index %= this->_tables.size();   //��ֹindexԽ�磬�ƻ�ȥ
            i++;

            //�����_state���ܶ��Ǵ��ڻ���ɾ������ô����Ϳ���������ѭ����������Ҫ���������˳�
            //����Ѿ�����һȦ����ô˵��ȫ�Ǵ���+ɾ��
            if(index == hashi){
                break;
            }
        }

        return nullptr;
    }

    bool Erase(const K& key){
        HashData<K,V>* ret = Find(key);
        if(ret){
            ret->_state = DELETE;
            this->_n--;
            return true;
        }
        else{
            return false;
        }
    }
private:
    vector <HashData<K, V>> _tables;  //��Hashֵ�����vector��
    size_t _n = 0;   //�洢�����ݸ���
};
