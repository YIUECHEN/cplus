#include<iostream>
#include<list>
#include<vector>
using namespace std;

void testList1(){

	list<int> l1;        //构造空的list
	list<int> l2(5, 10); //放5个值为10的元素
	list<int> l3(l2);    //拷贝构造

	//头插尾插
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_front(4);
	l1.push_front(5);

	list<int> l4(l1.begin(), l1.end());//用l1左闭右开的区间构造

	int mv[] = { 11, 22, 33, 44, 55 };
	list<int> l5(mv, mv + sizeof(mv) / sizeof(int));// 以数组为迭代器区间构造l5

	//迭代器遍历
	cout << "ll: ";
	for (list<int>::iterator it = l1.begin(); it != l1.end();++it){

		cout << *it << ' ';
	}
	cout << endl;

	//迭代器方式遍历
	cout << "l4: ";
	list<int>::reverse_iterator rit = l4.rbegin();
	while (rit != l4.rend()){

		cout << *rit << ' ';
		++rit;
	}
	cout << endl;

	//范围for方式遍历
	cout << "l2: ";
	for (auto e : l2){

		cout << e << ' ';

	}
	cout << endl;

	cout << "l3: ";

	for (auto e : l3){

		cout << e << ' ';

	}
	cout << endl;

	cout << "l5: ";
	for (auto e : l5){

		cout << e << ' ';

	}
	cout << endl;

	cout << "l1头删尾删后：";
	l1.pop_front();
	l1.pop_back();

	for (auto e : l1){

		cout << e << ' ';

	}
	cout << endl;
}

void testList2(){
	list<int> L;
	L.push_back(11);
	L.push_back(22);
	L.push_back(33);
    L.push_back(44);
	L.push_back(55);

	auto pos = ++L.begin();//打印第二个节点 22
	cout << *pos << endl;

	L.insert(pos, 99);//pos前插入
	for (auto e : L){

		cout << e << ' ';//11,99,22,33,44,55

	}
	cout << endl;

	list<int> l1{ 1, 2, 3 };
	L.insert(pos, l1.begin(), l1.end());//在pos前插入l1区间
	for (auto e : L){

		cout << e << ' ';

	}
	cout << endl;
	L.erase(pos);//删除pos位置的值
	for (auto e : L){

		cout << e << ' ';

	}
	cout << endl;
	list<int> l2{ 4, 5, 6 };
	l1.swap(l2);//交换l1和l2中的元素

	cout << "l1(123):";
	for (auto e : l1){

		cout <<e << ' ';

	}
	cout << endl;
	cout << "l2(456):";
	for(auto e : l2){

		cout <<  e << ' ';

	}
	cout << endl;
}
int main(){
	//testList1();
	testList2();
	system("pause");
	return 0;
}