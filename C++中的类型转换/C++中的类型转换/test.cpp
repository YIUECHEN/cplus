#include<iostream>
using namespace std;



class A
{
public:
	virtual void f(){}

	int _a;
};

class B : public A
{
	int _b;
};


void fun(A* pa)
{
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
int main(){
	/*
	int a = 10;
	double b = a;//隐式转化
	float c = 10.342;
	int d = c;//精度丢失

	int* p = (int*)a;//显示转换


	const int a1 = 10;

	int *p1 = (int*)&a1;
	*p1 = 20;
	cout << a1 << endl; //10放在寄存器中
	cout << *p1 << endl;//20
	*/


	//int a = 10;
	//double b = static_cast<double>(a);//相近类型
	//int* p =&a;
	//int address = reinterpret_cast<int>(p);//不相关类型


	//const int a1 = 20;

	//int* p1 = const_cast<int*>(&a1);//去掉const属性
	/*A a;
	fun(&a);*/


	A* pa = new B;
	B* p = dynamic_cast<B*>(pa);

	cout << p << endl;           
	return 0;
}