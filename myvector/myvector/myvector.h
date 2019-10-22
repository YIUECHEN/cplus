#include<iostream>
#include<assert.h>
#pragma once
using namespace std;

template<class T>
class myvector{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	iterator begin()
	{ 
		return _start; 
	}
	iterator end()
	{
		return _finish;
	}

	const_iterator cbegin()const
	{
		return _start;
	}
	const_iterator cend()const
	{
		return _finish;
	}

	myvector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endofcap(nullptr)
	{}

	myvector(int n, const T& val=T())
		: _start(nullptr)
		, _finish(nullptr)
		, _endofcap(nullptr)
	{
		reserve(n);
		while (n--){
			push_back(val);
		}
	}

	myvector(const myvector<T>& v)
		:_start(nullptr)
		, _finish(nullptr)
		, _endofcap(nullptr)
	{
		reserve(v.capacity());
		iterator it = begin();
		const_iterator vit = v.cbegin();
		while (vit!= v.cend()){
			*it++ = *vit++;
				
		}
		_finish = _start + v.size();
		_endofcap = _start + v.capacity();
	}
	//template(class InputIterator)
	myvector(iterator first, iterator last)
		:_start(nullptr)
		, _finish(nullptr)
		, _endofcap(nullptr)
	{
			reserve(last - first);
			while (first != last){
				push_back(*first);
				++first;	
			}
	}

	~myvector()
	{ 
		if (_start){
			delete[] _start;
			_start = _finish = _endofcap = nullptr;
		}
	
	} 

	void resize(size_t n,const T& val)
	{
		if (n < size()){
			_finsh = _start + n;
			return;
		}
		if (n > capacity()){
			reserve(n);
		}
		while (_finish!=_start+n){
			*_finish = val;
			++_finish;
		}
	
	}
	void reserve(size_t n)
	{
		if (n > capacity()){
			size_t sz = size();
			T* tmp = new T[n];
			if (_start){
				/*memcpy(tmp, _start, sizeof(T)*sz);
				*/
				for (size_t i = 0; i < sz; i++){
					tmp[i] = _start[i];
				
				}
				
			}
			_start = tmp;
			_finish = _start + sz;
			_endofcap = _start + n;
		}
	}

	void push_back(const T& x)
	{
		/*if (size()=capacity()){
			size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
			reserve(newcapacity);
		}
		*_finsh = x;
		++_finsh;*/
		insert(end(), x);
	}

	void pop_back()
	{
		assert(_finish > _start);
		--_finish;
		
	}

	void insert(iterator pos,const T&x)
	{
		if (_finish == _endofcap){
			size_t n = pos - _start;
			size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
			reserve(newcapacity);
			pos = _start + n;
		}
		iterator begin = _finish-1;
		while (pos<=begin){
			*(begin + 1) = *begin;
			--begin;
		}
		*pos = x;
		++_finish;
	}

	iterator erase(iterator pos)
	{
		assert(pos<_finish&&pos>_start);
		iterator begin = pos+1;
		while (begin!=_finish){
			*(begin-1) = *begin;
			++begin;
		}
		--_finish;
		return pos;
	}

	size_t size()const
	{
		return _finish - _start;
	}

	size_t capacity()const
	{
		return _endofcap-_start;
	}

	T& operator[](size_t pos)
	{
		return _start[pos];
	}

	

	myvector<T>& operator= (myvector<T> v)
	{
		swap(v);
		return *this;
	}
private: 
	iterator _start;
	iterator _finish;
	iterator _endofcap;

};


void testmyvector1()
{
	myvector<int> v1;
	myvector<int> v2(5,10);
	myvector<int> v3(v2.begin(),v2.end());

	//Î²²åÎ²É¾
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	
	myvector<int> v4(v1);

	int amv[] = { 10, 20, 30, 40, 50 };
	myvector<int> v5(amv, amv + sizeof(amv) / sizeof(int));

	v5.pop_back();
	v5.pop_back();
	//±éÀú·½Ê½
	for (myvector<int>::iterator it = v1.begin(); it < v1.end(); ++it){
		cout <<*it << " ";
	}
	cout << endl;

	for (myvector<int>::iterator it = v2.begin(); it < v2.end(); ++it){
		cout << *it << " ";

	}
	cout << endl;


	for (auto e : v3){
		cout << e << " ";
	}
	cout<<endl;

	for (auto e : v4){
		cout << e << " ";
	}
	cout << endl;

	for (size_t i = 0; i < v5.size(); ++i)
	{
		cout << v5[i] << " ";
	}
	cout << endl;
	
}

void testmyvector2(){
	int mv[] = { 11, 22, 33, 44, 55 };
	myvector<int> v1(mv, mv + sizeof(mv) / sizeof(int));

	for (myvector<int>::iterator it = v1.begin(); it < v1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	auto pos = find(v1.begin(), v1.end(), 22);

	v1.erase(pos);

	for (auto e : v1){
		cout << e << " ";
	}
	cout << endl;

	v1.insert(pos, 88);
	for (auto e : v1){
		cout << e << " ";
	}
	cout << endl;
}