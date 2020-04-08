#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//#if 0
int main(){
	[]{};//��򵥵�lamber���ʽ��������

	int a = 3, b = 4;
	auto func1 = [=]{return a + b; };
	cout << func1() << endl;//7
	
	//���ô��ݵķ�ʽ���Ըı������ֵ
	auto func2 = [&](int c){return b = (++a) + c; };//
	func2(10);
	cout << a << " " << b << " " << endl;
	
	auto func3 = [=](int c)mutable{return b = a + c; };
	func3(10);
	
	return 0;
}
//#endif



#if 0
struct Goods{
	string _name;
	double _price;
	int _evaluation;
};

bool priceCompare(Goods& g1,Goods& g2){
	return g1._price > g2._price;
}

bool evlCompare(Goods& g1, Goods& g2){
	return g1._evaluation > g2._evaluation;
}

class  priceCompareobj{
public:
	bool operator()(Goods& g1, Goods& g2){
		return g1._price > g2._price;
	}
};

class  evlCompareobj{
public:
	bool operator()(Goods& g1, Goods& g2){
		return g1._evaluation > g2._evaluation;
	}
};
int main(){
	vector<Goods> v{ { "ƻ��", 8, 5 }, { "�㽶", 6.5, 3 }, { "����", 3, 2 }, { "���", 5, 4 }, { "����", 4, 3 } };

	//����ָ��
	/*sort(v.begin(), v.end(), priceCompare);
	sort(v.begin(), v.end(), evlCompare);*/

	//�º���
	/*sort(v.begin(), v.end(), priceCompareobj());
	sort(v.begin(), v.end(), evlCompareobj());*/
	
	//lamber���ʽ
	//д��һ��
	auto pc = [](Goods& g1, Goods& g2)->bool{return g1._price > g2._price; };
	sort(v.begin(), v.end(), pc);
		
	auto ec = [](Goods& g1, Goods& g2)->bool{return g1._evaluation > g2._evaluation; };
	sort(v.begin(), v.end(), ec);


	//д������
	//����ֵ��д�ɲ�д������д��
	sort(v.begin(), v.end(), [](Goods& g1, Goods& g2)->bool{return g1._price > g2._price; });
	sort(v.begin(), v.end(), [](Goods& g1, Goods& g2){return g1._evaluation > g2._evaluation; });
	return 0;
}
#endif

//class Add{
//public:
//	Add(int n):_a(n){
//	}
//
//	int operator()(int n){
//		return _a + n;
//	}
//private:
//	int _a;
//};
//
//int main(){
//	int n = 2;
//	Add a1(n);
//	a1(4);
//
//	auto a2 = [=](int m)->int{return n + m; };
//	a2(4);
//	return 0;
//}