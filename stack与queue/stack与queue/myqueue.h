#include<deque>
#pragma once

template<class T,class con=deque<T>>
class myqueue{
public:
	myqueue(){}

	void push(const T& x){
		_q.push_back(x);
	}

	void pop(){
		_q.pop_front();
	}

	T& back(){
		return _q.back();
	}

	T& front(){
		return _q.front();
	}

	size_t size(){
		return _q.size();
	}

	bool empty(){
		return _q.empty();
	}

	void print(){
		for (auto e : _q){
			cout << e << " ";
		}
		cout << endl;
	}

private:
	con _q;

};

void testmyqueue(){
	myqueue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.print();
	cout << q.size() << " " << q.front() << " " << q.back() << endl;

	q.pop();
	q.pop();
	cout << q.size() << " " << q.front() << " " << q.back() << endl;

}