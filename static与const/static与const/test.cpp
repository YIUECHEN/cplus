#include<iostream>
using namespace std;

//class A{
//public:
//	A(int num):c(num){//const成员变量要在构造函数的初始化列表进行初始化
//	
//	}
//	void fun1(){
//		cout << a << endl;
//
//		cout << b << endl;
//		cout << c << endl;
//	}
//	const void fun2(int num){
//		//c = num;//error,
//		a = num;
//		cout << a<< endl;
//
//		num = num + c;
//		cout << num << endl;
//
//	}
//	static void fun3(){
//	
//		//cout << a << endl;//静态成员函数不能引用非静态成员变量
//		cout << b++ << endl;//只能引用、改变静态成员变量
//		cout << b << endl;//只能引用静态成员变量
//
//	}
//private:
//	int a=10;
//	//static int _id=10;//error
//	static int b;
//	const int c;
//
//};
//int A::b = 100;//static静态成员变量要在类外进行初始化
//int main(){
//	A number(12);
//	
//	number.fun1();//10  12
//	//number.fun2(2);//2+12=14
////	number.fun3();
//
//	return 0;
//}

#if 0
class A{
public:
	A(int a);
	static void print();//静态成员函数
private:
	static int aa;//静态成员变量的声明
	static const int count;//静态常量成员变量（可以在构造函数中初始化）
	const int bb;//常量成员变量
};

int A::aa = 0;//静态成员的定义+初始化
const int A::count = 25;//静态常量成员定义+初始化

A::A(int a) :bb(a){//常量成员的初始化
	aa += 1;
}

void A::print(){
	cout << "count=" << count << endl;
	cout << "aa=" << aa << endl;
}


void main(){
	A a(10);
	A::print();//通过类访问静态成员函数
	a.print();//通过对象访问静态成员函数
}
#endif

#if 0
class base{//派生类与基类共享基类的静态成员变量
public:
	static int _num;//声明 
};
int base::_num = 0;//静态数据成员的真正定义 

class derived :public base{ };

int main()
{
	base a;
	derived b;
	a._num++;
	cout << "base class static data number_num is:" << a._num << endl;
	b._num++;
	cout << "derived class static datanumber _num is:" << b._num << endl;
	return 0;
}
#endif

#if 0
class base{//静态成员变量可以成为成员函数的可选参数
public:
	static int _staticVar;
	int _var;
	void foo1(int i = _staticVar);//正确,_staticVar为静态数据成员 
	//void foo2(int i = _var);//错误,_var为普通数据成员 
};
#endif


class A{
public:
	static A a;//静态成员变量的类型可以是类类型
	//A b;//普通成员函数不可以是类类型
	A *c;//普通成员函数只能声明为所属类类型的指针或引用
	A &d;

};

int main(){
	return 0;
}