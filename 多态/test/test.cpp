#include<iostream>
using namespace std;

class A{
public:
	virtual void print(){//�����б������麯�������������Ի��۵��麯��������д
		cout << "A::print()" << endl;
	}
	int _a;
};

class B:public A{
public:
	virtual void print(){//��������Բ��üӹؼ��� ���ǲ��淶
		cout << "B::print()" << endl;
	}
	int b;
};

void fun(A& a){//���û�����麯��������ָ������õķ�ʽ
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

