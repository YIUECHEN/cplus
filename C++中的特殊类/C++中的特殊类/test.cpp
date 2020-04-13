#include<iostream>
using namespace std;

//设计一个类只能在堆上创建对象

/*class A{
public:
	static A* getA(){
		return new A;
	}
private:
	A(){
		cout << "A()" << endl;
	}

	//C++98中只声明不实现
	A(const A& a);

	////C++中使用delete
 //   A(const A& a) = delete;
};*/

//设计实现一个只在栈上创建对象的类
/*
class A{
public:
	static A getA(){
		return A();
	}
private:
	A(){
		cout << "A()" << endl;
	}

};*/

/*
class A{
public:
	A(){
		cout << "A()" << endl;
	}
private:
	void* operator new(size_t size);
	void operator delete(void* p);

};
*/

//设计一个防拷贝的类
/*
class A{
public:
	A(){}
	A(const A& a) = delete;
private:
	A(const A& a);
}; */

//设计一个只有一个对象的类（单例模式）
//饿汉模式
/*
class A{
public:
	static A& getA(){
		return a;
	}

private:
	A(){}
	A(const A&) = delete;
	static A a;
};

A A::a;
*/

#include<vector>
#include<mutex>
#include<thread>
class A{
public:
	static A& getA(){
		if (a == nullptr){
			mut.lock();
			if (a == nullptr){
				a = new A;
			}
			mut.unlock();
		}
		return *a;
	}

private:
	A(){}
	A(const A&) = delete;
	static A* a;
	static mutex mut;
};

A* A::a=nullptr;
mutex A::mut;


int main(){
	//A a; error
	/*A* a1 = A::getA();
	A* a2(a1);*/
	//A a1;
	//A a2(a1);//error

/*
	cout << &A::getA() << endl;
	cout << &A::getA() << endl;
	cout << &A::getA() << endl;
	cout << &A::getA() << endl;
	cout << &A::getA() << endl;*/

	vector<thread> v;
	for (int i = 0; i < 4; i++){
		v.push_back(thread([]{
			this_thread::sleep_for(std::chrono::seconds(1));

			for (int j = 0; j < 10; j++){
				cout << &A::getA() << endl;
			}
		}));
	}

	for (int i = 0; i < 4; i++){
		v[i].join();
	}
	return 0;
}