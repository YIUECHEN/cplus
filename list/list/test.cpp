#include<iostream>
#include<list>
#include<vector>
using namespace std;

void testList1(){

	list<int> l1;        //����յ�list
	list<int> l2(5, 10); //��5��ֵΪ10��Ԫ��
	list<int> l3(l2);    //��������

	//ͷ��β��
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_front(4);
	l1.push_front(5);

	list<int> l4(l1.begin(), l1.end());//��l1����ҿ������乹��

	int mv[] = { 11, 22, 33, 44, 55 };
	list<int> l5(mv, mv + sizeof(mv) / sizeof(int));// ������Ϊ���������乹��l5

	//����������
	cout << "ll: ";
	for (list<int>::iterator it = l1.begin(); it != l1.end();++it){

		cout << *it << ' ';
	}
	cout << endl;

	//��������ʽ����
	cout << "l4: ";
	list<int>::reverse_iterator rit = l4.rbegin();
	while (rit != l4.rend()){

		cout << *rit << ' ';
		++rit;
	}
	cout << endl;

	//��Χfor��ʽ����
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

	cout << "l1ͷɾβɾ��";
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

	auto pos = ++L.begin();//��ӡ�ڶ����ڵ� 22
	cout << *pos << endl;

	L.insert(pos, 99);//posǰ����
	for (auto e : L){

		cout << e << ' ';//11,99,22,33,44,55

	}
	cout << endl;

	list<int> l1{ 1, 2, 3 };
	L.insert(pos, l1.begin(), l1.end());//��posǰ����l1����
	for (auto e : L){

		cout << e << ' ';

	}
	cout << endl;
	L.erase(pos);//ɾ��posλ�õ�ֵ
	for (auto e : L){

		cout << e << ' ';

	}
	cout << endl;
	list<int> l2{ 4, 5, 6 };
	l1.swap(l2);//����l1��l2�е�Ԫ��

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