#include<iostream>
//#include<memory>
#include<mutex>
#include<thread>
#include<vector>
using namespace std;

//设计智能指针解决的问题
/*
void fun(){
	if (1 < 2){
		throw"异常";
	}
	return;
}

int main(){
	int* array = new int[10];
	//fun();//抛出异常后，造成内存泄漏
	delete[] array;
	return 0;
}
*/
//template<class T>
//class autoptr{
//public:
//	autoptr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	autoptr(autoptr<T>& at)
//		:_ptr(at._ptr)
//	{
//		at._ptr = nullptr;
//	}
//
//	autoptr<T>& operator=(autoptr<T>& ap){
//		if (this != ap){
//			if (_ptr)
//				delete _ptr;
//			_ptr = ap._ptr;
//			ap._ptr = nullptr;
//		}
//	}
//
//	T& operator*(){
//		return *_ptr;
//	}
//
//	T* operator->(){
//		return _ptr;
//	}
//
//	~autoptr()
//	{
//		if (_ptr){
//			cout << "delete[]" << _ptr << endl;
//			delete[] _ptr;
//		}
// 	}
//private:
//	T* _ptr;
//};
//
//struct A{
//	int _a1;
//	int _a2;
//};
//void test_autoptr1(){
//	int *p1 = new int;
//	*p1 = 10;
//
//	autoptr<int> ap1(new int);
//	*ap1 = 10;
//
//	A* pa = new A;
//	(*pa)._a1 = 10;
//	pa->_a2 = 20;
//
//	autoptr<A> ap2(new A);
//	(*ap2)._a1 = 10;
//	ap2->_a2 = 20;
//	
//}
//
//void test_autoptr2(){
//	autoptr<int> ap1(new int);
//	autoptr<int> ap2(ap1);
//	autoptr<int> ap3 = ap2;
//
//	*ap1 = 10;//error
//}
//
//template<class T> 
//class uniqueptr{
//public:
//	uniqueptr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//
//	T& operator*(){
//		return *_ptr;
//	}
//
//	T* operator->(){
//		return _ptr;
//	}
//
//	~uniqueptr()
//	{
//		if (_ptr){
//			cout << "delete[]" << _ptr << endl;
//			delete[] _ptr;
//		}
//	}
//
//	//C++11防拷贝
//	/*uniqueptr(const uniqueptr<T>&)=delete;
//	uniqueptr<T>& operator=(const uniqueptr<T>&) = delete;*/
//private:
//	//C++98防拷贝：只声明不实现+声明成私有
//	uniqueptr(const uniqueptr<T>&);
//	uniqueptr<T>& operator=(const uniqueptr<T>&);
//
//private:
//	T* _ptr;
//};
//void test_uniqueptr(){
//	uniqueptr<int> up1(new int);
//	//uniqueptr<int> up2(up1);//无法调用
//	//uniqueptr<int> up2=up1;//无法调用
//}
//template<class T>
//class sharedptr{
//public:
//	sharedptr(T* ptr)
//		:_ptr(ptr),
//		_pCount(new int(1))
//	{}
//
//	sharedptr(const sharedptr<T>& sp)
//		:_ptr(sp._ptr),
//		_pCount(sp._pCount)
//	{
//		++(*_pCount);
//
//	}
//	
//	sharedptr<T>& operator=(const sharedptr<T>& sp){
//		if (_ptr != sp._ptr){
//			if (--(*_pCount) == 0){
//				delete _pCount;
//				if (_ptr){
//					delete _ptr;
//				}
//			}
//			_ptr = sp._ptr;
//			_pCount = sp._pCount;
//			++(*_pCount);
//		}
//		return *this;
//	}
//
//	~sharedptr(){
//		if (--(*_pCount) == 0){
//			delete _pCount;
//			if (_ptr){
//				cout << "delete:" << _ptr << endl;
//				delete _ptr;
//			}
//		}
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//	int* _pCount;
//};
//
//void test_sharedptr(){
//
//	sharedptr<int> sp1(new int);
//	sharedptr<int> copy1(sp1);
//	sharedptr<int> copy2(copy1);
//
//	sharedptr<int> sp3(new int);
//	sharedptr<int> sp4(sp3);
//
//	sp1 = sp4;
//	sp3 = sp4;
//
//}
//int main(){
//	//test_autoptr();
//	//test_uniqueptr();
//	test_sharedptr();
//	return 0;
//}


template<class T>
class sharedptr{
public:
	sharedptr(T* ptr=nullptr)
		:_ptr(ptr),
		_pCount(new int(1)),
		_pMtx(new mutex)
	{}

	sharedptr(const sharedptr<T>& sp)
		:_ptr(sp._ptr),
		_pCount(sp._pCount),
		_pMtx(sp._pMtx)

	{
		AddRef();

	}

	sharedptr<T>& operator=(const sharedptr<T>& sp){
		if (_ptr != sp._ptr){
			if (--(*_pCount) == 0){
				delete _pCount;
				if (_ptr){
					delete _ptr;
				}
			}
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			_pMtx = sp._pMtx;
			AddRef();
		}
		return *this;
	}

	//加引用计数
	void AddRef(){
		//_pMtx->lock();
		++(*_pCount);
		//_pMtx->unlock();
	}

	//减引用计数
	void ReleaseRef(){
		bool deleteflag = false;
		//_pMtx->lock();
		if (--(*_pCount) == 0){
			delete _pCount;
			cout << "delete:" << _ptr << endl;
			delete _ptr;
			deleteflag = true;
		}
		//_pMtx->unlock();
		if (deleteflag == true){
			delete _pMtx;
		}
	}


	~sharedptr(){
		ReleaseRef();
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
	T* GetPtr()const{
		return _ptr;
	}
	
	int GetRefCount(){
		return *_pCount;
	}

private:
	T* _ptr;
	int* _pCount;
	mutex* _pMtx;
};
void test_sharedptr(){
	sharedptr<int> sp(new int(0));
	cout << "New:"<<sp.GetPtr() << endl;
	vector<thread> vthreads;
	const int thread_size = 4;
	for (int i = 0; i < thread_size; i++){
		vthreads.push_back(thread([&](){
			for (int i = 0; i < 10000; i++){
				sharedptr<int> copy(sp);
				++(*sp);
			}
		}));
	}
	
	for (int i = 0; i < thread_size; i++){
		vthreads[i].join();
	}
	cout << *sp << endl;

}

template<class T>
class weakptr{
public:
	weakptr()
		:_ptr(nullptr)
	{}
	weakptr(const sharedptr<T>& sp)
		:_ptr(sp.GetPtr())
	{}
	weakptr<T>& operator=(const sharedptr<T>& sp)
	{
		_ptr = sp.GetPtr();
		return *this;
	}

	~weakptr()
	{}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;

};


struct ListNode{
	/*sharedptr<ListNode> _next;
	sharedptr<ListNode> _prev;*/
	weakptr<ListNode> _next;
	weakptr<ListNode> _prev;
	int _val;
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
	
};

void test_cycle_ref()
{
	sharedptr<ListNode> node1(new ListNode);
	sharedptr<ListNode> node2(new ListNode);

	// 循环引用
	node1->_next = node2;
	node2->_prev = node1;

	cout << node1.GetRefCount() << endl;
	cout << node2.GetRefCount() << endl;
}
int main(){
	//test_sharedptr();
	test_cycle_ref();
	

	return 0;
}
