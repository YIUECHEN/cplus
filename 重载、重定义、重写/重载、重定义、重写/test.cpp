#include<iostream>
using namespace std;

//重载
//int add(int a, int b){
//	cout << "int_int_int" << endl;
//	return a + b;
//}
//
//double add(double a, double b){
//	cout << "double_double_double" << endl;
//	return a + b;
//}
//
//int add(int a, double b){
//	cout << "int_int_double" << endl;
//	return a + b;
//}
//
//int main(){
//	
//	add(1, 2);
//	add(1.0, 2.0);
//	add(1, 2.0);
//	return 0;
//}

//重定义
//class A{
//public:
//	void print(){
//		cout << "A::print()" << endl;
//	}
//
//	int _a1;
//	int _a2;
//};
//class B:public A{
//public:
//	void print(int x){
//		cout << "B::print()" << endl;
//	}
//
//	int _a2;
//};
//
//int main(){
//	B b;
//	b._a2 = 10;
//	b.A::_a2 = 20;
//	b.print(2); //B::print()
//	b.A::print();//A:;print()
//	return 0;
//}

//重写
class A{
public:
	virtual void print(){
		cout << "A::print()" << endl;
	}

	int _a1;
};
class B :public A{
public:
	virtual void print(){
		cout << "B::print()" << endl;
	}

	int _b;
};

void fun(A& a){
	a.print();
}
int main(){
	A a;
	B b;
	
	fun(a);
	fun(b);
	return 0;
}



