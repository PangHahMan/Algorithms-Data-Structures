#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class K, class V>
struct HashNode
{
	HashNode<K, V> *_next;
	pair<K, V> _kv;

	HashNode(const pair<K, V> &kv)
	{
		this->_kv = kv;
		this->_next = nullptr;
	}
};

template <class K>
struct HashFunc
{
	size_t operator()(const K &key)
	{
		return key;
	}
};

// 特化模板，传string的话，就走这个
template <>
struct HashFunc<string>
{
	size_t operator()(const string &s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
			hash *= 31;
		}
		return hash;
	}
};

template <class K, class V, class Hash = HashFunc<K>> // Hash用于将key转换成可以取模的类型
class HashTable
{
	typedef HashNode<K, V> Node;

public:
	~HashTable()
	{
		for (auto &cur : this->_tables)
		{
			while (cur)
			{
				Node *next = cur->_next;
				delete cur;
				cur = next;
			}
			cur = nullptr;
		}
	}

	Node *Find(const K &key)
	{
		if (this->_tables.size() == 0)
		{
			return nullptr;
		}

		Hash hash;
		size_t hashi = hash(key) % this->_tables.size();
		Node *cur = this->_tables[hashi];
		while (cur)
		{
			if (cur->_kv.first == key)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return nullptr;
	}

	bool Erase(const K &key)
	{
		Hash hash;
		size_t hashi = hash(key) % this->_tables.size();
		Node *prev = nullptr;
		Node *cur = this->_tables[hashi];
		while (cur)
		{
			if (cur->_kv.first == key)
			{
				if (prev == nullptr)
				{
					this->_tables[hashi] = cur->_next;
				}
				else
				{
					prev->_next = cur->_next;
				}
				delete cur;
				return true;
			}
			else
			{
				prev = cur;
				cur = cur->_next;
			}
		}
		return false;
	}

	// 扩容优化，使用素数扩容
	size_t GetNextPrime(size_t prime)
	{
		// SGI
		static const int __stl_num_primes = 28;
		static const unsigned long __stl_prime_list[__stl_num_primes] = {
			53, 97, 193, 389, 769, 1543,
			3079, 6151, 12289, 24593, 49157, 98317,
			196613, 393241, 786433, 1572869, 3145739, 6291469,
			12582917, 25165843, 50331653, 100663319, 201326611, 402653189,
			805306457, 1610612741, 3221225473, 4294967291};

		size_t i = 0;
		for (; i < __stl_num_primes; ++i)
		{
			if (__stl_prime_list[i] > prime)
				return __stl_prime_list[i];
		}

		return __stl_prime_list[i];
	}

	bool Insert(const pair<K, V> &kv)
	{
		Hash hash; // 仿函数用于不能取模的值
		// 已经有这个数，就不用插入了
		if (Find(kv.first))
		{
			return false;
		}

		// 负载因子 == 1时扩容
		if (this->n == this->_tables.size())
		{
			// size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			size_t newsize = this->GetNextPrime(_tables.size());
			vector<Node *> newtables(newsize, nullptr);
			for (auto &cur : this->_tables)
			{ // cur是Node*
				while (cur)
				{
					// 保存下一个
					Node *next = cur->_next;
					// 头插到新表
					size_t hashi = hash(cur->_kv.first) % newtables.size();
					cur->_next = newtables[hashi];
					newtables[hashi] = cur;

					cur = next;
				}
			}
			_tables.swap(newtables);
		}

		size_t hashi = hash(kv.first) % this->_tables.size();
		// 头插
		Node *newnode = new Node(kv);
		newnode->_next = _tables[hashi];
		_tables[hashi] = newnode;
		this->n++;

		return true;
	}

	// 获取哈希表索引最大长度(哈希桶长度)
	size_t MaxBucketSize()
	{
		size_t max = 0;
		for (int i = 0; i < _tables.size(); ++i)
		{
			auto cur = _tables[i];
			size_t size = 0;
			while (cur)
			{
				++size;
				cur = cur->_next;
			}

			printf("[%d]->%d\n", i, size);

			if (size > max)
			{
				max = size;
			}
			if (max == 5121)
			{
				printf("%d", i);
				break;
			}
		}

		return max;
	}

private:
	vector<Node *> _tables;
	size_t n = 0; // 存储有效数据的个数
};