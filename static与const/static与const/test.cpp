#include<iostream>
using namespace std;

//class A{
//public:
//	A(int num):c(num){//const��Ա����Ҫ�ڹ��캯���ĳ�ʼ���б���г�ʼ��
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
//		//cout << a << endl;//��̬��Ա�����������÷Ǿ�̬��Ա����
//		cout << b++ << endl;//ֻ�����á��ı侲̬��Ա����
//		cout << b << endl;//ֻ�����þ�̬��Ա����
//
//	}
//private:
//	int a=10;
//	//static int _id=10;//error
//	static int b;
//	const int c;
//
//};
//int A::b = 100;//static��̬��Ա����Ҫ��������г�ʼ��
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
	static void print();//��̬��Ա����
private:
	static int aa;//��̬��Ա����������
	static const int count;//��̬������Ա�����������ڹ��캯���г�ʼ����
	const int bb;//������Ա����
};

int A::aa = 0;//��̬��Ա�Ķ���+��ʼ��
const int A::count = 25;//��̬������Ա����+��ʼ��

A::A(int a) :bb(a){//������Ա�ĳ�ʼ��
	aa += 1;
}

void A::print(){
	cout << "count=" << count << endl;
	cout << "aa=" << aa << endl;
}


void main(){
	A a(10);
	A::print();//ͨ������ʾ�̬��Ա����
	a.print();//ͨ��������ʾ�̬��Ա����
}
#endif

#if 0
class base{//����������๲�����ľ�̬��Ա����
public:
	static int _num;//���� 
};
int base::_num = 0;//��̬���ݳ�Ա���������� 

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
class base{//��̬��Ա�������Գ�Ϊ��Ա�����Ŀ�ѡ����
public:
	static int _staticVar;
	int _var;
	void foo1(int i = _staticVar);//��ȷ,_staticVarΪ��̬���ݳ�Ա 
	//void foo2(int i = _var);//����,_varΪ��ͨ���ݳ�Ա 
};
#endif


class A{
public:
	static A a;//��̬��Ա���������Ϳ�����������
	//A b;//��ͨ��Ա������������������
	A *c;//��ͨ��Ա����ֻ������Ϊ���������͵�ָ�������
	A &d;

};

int main(){
	return 0;
}