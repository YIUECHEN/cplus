#include<iostream>
using namespace std;

class B{
public:
	B():_b(){
		cout << "B()" << endl;
	}

	~B(){
		cout << "~B()" << endl;
	}


	void print(){
		cout << _b << endl;
	}
	int _b;
};

class D:public B{
public:
	D(int n):_d(n){
		cout << "D()" << endl;
	}

	void print(){
		cout << _d << endl;
	}
	  
	~D(){
		cout << "~D()" << endl;
	}
	int _d;
};

int main(){
	D d1(5);
	d1.print();

	system("pause");
	return 0;

}