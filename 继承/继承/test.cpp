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
//class D :public B{//error C3246: ��D��: �޷��ӡ�B���̳У���Ϊ���ѱ�����Ϊ��final��	
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
//	d1.B::set(10);//ͨ�����ַ�ʽ���ʻ����Ա
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
//	B b(d);//������Ķ�����Ը�ֵ������Ķ������á�ָ��
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
//	//D d1(b1);//����Ķ��󲻿��Ը�ֵ��������
//
//	//D* d1 = &b1;error
//	D* d1 = (D*)&b1;//�����ָ�����ͨ��ǿ������ת���ķ�ʽ��ֵ���������ָ��
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
//private://��Ԫ�������ܼ̳У�������Ԫ�������ܵ����������˽�г�Ա�򱣻���Ա
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