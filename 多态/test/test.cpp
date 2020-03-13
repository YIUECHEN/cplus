#include<iostream>
using namespace std;

class A{
public:
	virtual void print(){//基类中必须有虚函数，派生类必须对积累的虚函数进行重写
		cout << "A::print()" << endl;
	}
	int _a;
};

class B:public A{
public:
	virtual void print(){//派生类可以不用加关键字 但是不规范
		cout << "B::print()" << endl;
	}
	int b;
};

void fun(A& a){//调用基类的虚函数必须用指针或引用的方式
	a.print();
}
int main(){
	A a;
	B b;
	fun(a);//A::print()
	fun(b);//B::print()
	system("pause");
	return 0;
}

