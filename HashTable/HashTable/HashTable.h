#pragma once
#include<iostream>
#include<vector>
using namespace std;

enum State{ EXIST,EMPTY,DELETE };

template<class T>
struct Elem{
	T _value;
	State _state;
};

template<class T, bool IsLine = true>
class HashTable{
public:
	HashTable(size_t capacity = 10)
		:_ht(capacity),
		_size(0)
	{
		for (auto& e : _ht)
 			e._state = EMPTY;
	}
	 
	bool Insert(const T& value){
		//检测是否扩容
		CheckCapacity();
		//通过哈希函数计算应插入的位置
		size_t Hashaddr = HashFunc(value);
		int i = 0;
		//检测插入的位置
		while (EMPTY != _ht[Hashaddr]._state){
			if (EXIST == _ht[Hashaddr]._state&&value == _ht[Hashaddr]._value){
				return false;
			}
			i++;
		//线性探测
			if (IsLine){
				++Hashaddr;
				if (Hashaddr == _ht.capacity())
					Hashaddr = 0;
			}
			else{
				Hashaddr += 2 * i + 1;
				Hashaddr %= _ht.capacity();
			}
			
		}
		//插入元素
		_ht[Hashaddr]._value = value;

		_ht[Hashaddr]._state = EXIST;
		_size++;
		return true;
	}
	 
	int Find(const T& value){
		size_t Hashaddr = HashFunc(value);
		int i = 0;
		while (EMPTY != _ht[Hashaddr]._state){
			if (EXIST == _ht[Hashaddr]._state && value == _ht[Hashaddr]._value){
				return Hashaddr;
			}
			i++;

			if (IsLine){
				++Hashaddr;
				if (Hashaddr == _ht.capacity())
					Hashaddr = 0;
			}
			else{
				Hashaddr += 2 * i + 1;
				Hashaddr %= _ht.capacity();
			}
		}
		return -1;
	}

	bool Erase(const T& value){
		int pos = Find(value);
		if (pos != -1){
			_ht[pos]._state = DELETE;
			_size--;
			return true;
		}
		return false;
	}

	void Swap(HashTable<T>& ht){
		_ht.swap(ht._ht);
		swap(_size, ht._size);
	}
private:
	size_t HashFunc(const T& value){
		return  value % _ht.capacity();
	}
	void CheckCapacity(){
		if (_size * 10 /_ht. capacity() >= 7){
			HashTable<T> newht(_ht.capacity() * 2);
			for (int i = 0; i < _ht.capacity(); i++){
				if (EXIST == _ht[i]._state){
					newht.Insert(_ht[i]._value);
				}
			}
			Swap(newht);
		}
	}

private:
	vector<Elem<T>> _ht;
	size_t _size;  //记录哈希表中有效元素的个数
};