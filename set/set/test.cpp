#include<iostream>
#include<set>
using namespace std;

void testSet1(){
	int array[] = { 77, 33, 44, 22, 11 , 77 };
	set<int> s(array, array + 5);
	for (auto it = s.begin(); it != s.end(); it++){//按小于排序，去重
		cout << *it << " ";
	}
	cout << endl;
	s.insert(66);//插入数据后依旧有序
	s.insert(99);

	for (auto it = s.rbegin(); it != s.rend(); it++){//按大于排序
		cout << *it << " ";
	}
}

void testSet2(){
	set<int> s;
	s.insert(40);
	s.insert(70);
	s.insert(10);
	s.insert(20);
	s.insert(90);

	auto it = s.find(10);
	s.erase(it);

	if (!s.empty()){//
		cout << *s.begin() << endl;//10被删除，20为第一个元素
		s.erase(s.begin());
	}
	for (auto it = s.begin(); it != s.end(); it++){//按小于排序，去重
		cout << *it << " ";
	}
	cout << endl;
	cout << "s的size "<< s.size() << endl;;
}

void testSet3(){
	int array[] = { 12, 75, 10, 32, 20, 25 };
	set<int> first(array, array + 3);     // 10,12,75
	set<int> second(array + 3, array + 6);  // 20,25,32
	set<int> third;
	third = first;
	cout << "third contains:";
	for (auto e : third){
		cout << e <<' ';
	}
	cout << endl;

	first.swap(second);
	cout << "first contains:";
	for (auto it = first.begin(); it != first.end(); ++it)
		cout << *it << ' ';
	cout << endl;

	cout << "second contains:";
	for (auto it = second.begin(); it != second.end(); ++it)
		cout << *it << ' ';
	cout << endl;


}

int main(){
	//testSet1();
	testSet2();
	//testSet3();

	system("pause");
	return 0;
}