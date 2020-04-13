#include<iostream>
using namespace std;

//���һ����ֻ���ڶ��ϴ�������

/*class A{
public:
	static A* getA(){
		return new A;
	}
private:
	A(){
		cout << "A()" << endl;
	}

	//C++98��ֻ������ʵ��
	A(const A& a);

	////C++��ʹ��delete
 //   A(const A& a) = delete;
};*/

//���ʵ��һ��ֻ��ջ�ϴ����������
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

//���һ������������
/*
class A{
public:
	A(){}
	A(const A& a) = delete;
private:
	A(const A& a);
}; */

//���һ��ֻ��һ��������ࣨ����ģʽ��
//����ģʽ
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