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
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
int main(){
	/*
	int a = 10;
	double b = a;//��ʽת��
	float c = 10.342;
	int d = c;//���ȶ�ʧ

	int* p = (int*)a;//��ʾת��


	const int a1 = 10;

	int *p1 = (int*)&a1;
	*p1 = 20;
	cout << a1 << endl; //10���ڼĴ�����
	cout << *p1 << endl;//20
	*/


	//int a = 10;
	//double b = static_cast<double>(a);//�������
	//int* p =&a;
	//int address = reinterpret_cast<int>(p);//���������


	//const int a1 = 20;

	//int* p1 = const_cast<int*>(&a1);//ȥ��const����
	/*A a;
	fun(&a);*/


	A* pa = new B;
	B* p = dynamic_cast<B*>(pa);

	cout << p << endl;           
	return 0;
}