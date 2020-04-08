#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//#if 0
int main(){
	[]{};//最简单的lamber表达式，无意义

	int a = 3, b = 4;
	auto func1 = [=]{return a + b; };
	cout << func1() << endl;//7
	
	//引用传递的方式可以改变变量的值
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
	vector<Goods> v{ { "苹果", 8, 5 }, { "香蕉", 6.5, 3 }, { "橘子", 3, 2 }, { "甜橙", 5, 4 }, { "菠萝", 4, 3 } };

	//函数指针
	/*sort(v.begin(), v.end(), priceCompare);
	sort(v.begin(), v.end(), evlCompare);*/

	//仿函数
	/*sort(v.begin(), v.end(), priceCompareobj());
	sort(v.begin(), v.end(), evlCompareobj());*/
	
	//lamber表达式
	//写法一：
	auto pc = [](Goods& g1, Goods& g2)->bool{return g1._price > g2._price; };
	sort(v.begin(), v.end(), pc);
		
	auto ec = [](Goods& g1, Goods& g2)->bool{return g1._evaluation > g2._evaluation; };
	sort(v.begin(), v.end(), ec);


	//写法二：
	//返回值可写可不写，建议写上
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