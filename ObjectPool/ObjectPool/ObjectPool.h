//定长内存池
#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class T, size_t initNum = 100>
class ObjectPool{
public:
	ObjectPool(){
		_start = (char*)malloc(sizeof(T)*initNum);
		_end = _start + sizeod(T)*initNum;
	}

	//申请一个对象
	T* New(){

		if (_start == _end){
			_start = (char*)malloc(sizeof(T)*initNum);
			_end = _start + sizeod(T)*initNum;
		}
		//从内存池开辟空间
		T* obj = (T*)_start;
		_start += sizeof(T);

		//给这份空间初始化（new定位表达式）
		new(obj)T;//对已存在的空间调用构造函数进行初始化
		return obj;
	}

	//释放开辟出去的内存
	void* Delete(T* ptr){
		//调用析构函数清理这块空间上的资源
		ptr->~T();

		//还到链表中（前一块存储后一块的地址）头插
		*(int*)ptr = _freeList;//强转（int*），再解引用，头四个字节存储地址
		_freeList = ptr;


	}
private:
	char* _start = nullptr;
	char* _end = nullptr;//管理内存池指针
	T* _freeList = nullptr;
};

void TestObjectPool(){
	ObjectPool<string> pool;
	string* p1 = pool.New();
	string* p2 = pool.New();

	cout << p1 << endl;
	cout << p2 << endl;

	pool.Delete(p1);
	pool.Delete(p2);

	string* p3 = pool.New();
	string* p4 = pool.New();
	string* p5 = pool.New();

	cout << p3 << endl;
	cout << p4 << endl;
	cout << p5 << endl;

}