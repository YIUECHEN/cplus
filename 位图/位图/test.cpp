#include"BitSet.h"
#include<iostream>

int main(){
	BitSet<50> bs;
	int array[] = { 1, 3, 7, 4, 12, 16, 19, 13, 22, 18 };
	for (auto e : array){
		bs.set(e);
	}

	cout << bs.size() << endl;
	cout << bs.count() << endl;

	if (bs.test(12)){
		cout << "12 is in bs" << endl;
	}
	else{
		cout << "12 is not in bs" << endl;

	}
	bs.reset(12);
	if (bs.test(12)){
		cout << "12 is in bs" << endl;
	}
	else{
		cout << "12 is not in bs" << endl;

	}

	return 0;
}