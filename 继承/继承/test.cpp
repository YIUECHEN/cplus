#include<iostream>
using namespace std;

//class B{
//public:
//	B():_b(){
//		cout << "B()" << endl;
//	}
//
//	~B(){
//		cout << "~B()" << endl;
//	}
//
//
//	void print(){
//		cout << _b << endl;
//	}
//	int _b;
//};
//
//class D:public B{
//public:
//	D(int n):_d(n){
//		cout << "D()" << endl;
//	}
//
//	void print(){
//		cout << _d << endl;
//	}
//	  
//	~D(){
//		cout << "~D()" << endl;
//	}
//	int _d;
//};

//class B final{
//public:
//	B(){
//		cout << "B()" << endl;
//	}
//
//	~B(){
//		cout << "~B()" << endl;
//	}
//
//
//	void print(){
//		cout << _b << endl;
//	}
//	int _b;
//};
//
//class D :public B{//error C3246: “D”: 无法从“B”继承，因为它已被声明为“final”	
//public:
//	D(int n) :_d(n){
//		cout << "D()" << endl;
//	}
//
//	
//
//	~D(){
//		cout << "~D()" << endl;
//	}
//	int _d;
//};

//class B{
//public:
//	void set(int n){
//		b = n;
//		cout << "D::set()" << endl;
//
//	}
//	int b;
//
//};
//
//class D:public B{
//public:
//	void set(int n){
//		b = n;
//		cout << "B::set()" << endl;
//	}
//	char b;
//};
//
//int main(){
//	D d1;
//	d1.set(5);
//	d1.B::set(10);//通过这种方式访问基类成员
//	system("pause");
//	return 0;
//
//}

//class B{
//public:
//	void set(int n){
//		_b = n;
//		cout << "B::set()" << endl;
//
//	}
//	int _b;
//
//};
//
//class D :public B{
//public:
//	void set(int n){
//		_d = n;
//		cout << "B::set()" << endl;
//	}
//	int _d;
//};
//int main(){
//	D d;
//	d.set(1);
//	B b(d);//派生类的对象可以赋值给基类的对象、引用、指针
//	B* bptr = &d;
//	B& bs = d;
//
//	b.set(0);//B::set()
//	bptr->set(5);//B::set()
//	bs.set(10);//B::set()
//
//	cout << endl;
//	B b1;
//	b1.set(20);
//	//D d1(b1);//基类的对象不可以赋值给派生类
//
//	//D* d1 = &b1;error
//	D* d1 = (D*)&b1;//基类的指针可以通过强制类型转换的方式赋值给派生类的指针
//	d1->set(12);//D::set()
//	system("pause");
//	return 0;
//}

//class B{
//public:
//	B(){
//		cout << "B()" << endl;
//	}
//	~B(){
//		cout << "~B()" << endl;
//	}
//
//
//};
//
//class D:public B{
//public:
//	D(){
//		cout << "D()" << endl;
//	}
//	~D(){
//		cout << "~D()" << endl;
//	}
//};
//
//int main(){
//	D d;
//	D* dptr = &d;
//	delete dptr;
//	system("pause");
//	return 0;
//}

//class D;
//class B{
//public:
//	friend void print(B& b, D& d);
//	int _b;
//};
//
//class D:public B{
//private://友元函数不能继承，基类友元函数不能调用派生类的私有成员或保护成员
//	int _d;
//
//};
//
//void print(B& b, D& d){
//	cout << b._b << endl;
//	cout << d._d << endl;//error
//}
//int main(){
//	B b;
//	D d;
//	print(b,d);
//	return 0;
//}

class A{
public:
	int _a;
	int a2;
};

//class B : public A{

class B :virtual public A{
public:
	int _b;
};

//class C : public A{
class C :virtual public A{
public:
	int _c;
};

class D :public B, public C{
public:
	int _d;
};

int main(){
	D d;

	cout << sizeof(D) << endl;
	d.B::_a = 1;
    d.C::_a = 2;
	d.a2 = 10;

	d._b = 3;
	d._c = 4;
	d._d = 5;
	system("pause");
	return 0;
}