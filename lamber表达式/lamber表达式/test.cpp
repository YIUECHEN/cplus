#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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