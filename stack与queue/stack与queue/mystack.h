#include<deque>
#pragma once

template<class T,class con=deque<T>>
class mystack{
public:
	mystack(){};

	void push(const T& x){
		_s.push_back(x);
	}

	void pop(){
		_s.pop_back();
	}

	T& top(){
		return _s.back();
	}

	size_t size(){
		return _s.size();
	
	}

	bool empty(){
		return _s.empty();
	}
	void print(){
		for (auto e : _s){
			cout << e << " ";
		}
		cout << endl;
	}
private:
	con _s;
};

void testmystack(){
	mystack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.print();
	cout << s.size() << " "<<s.top() << endl;

	s.pop();
	s.pop();
	s.print();
	cout << s.size() << " " << s.top() << endl;
}