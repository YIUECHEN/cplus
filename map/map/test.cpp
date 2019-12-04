#include<iostream>
#include<map>
#include<string>
using namespace std;


void testMap1(){
	map<string, string> m;
	m.insert(pair<string, string>("peach", "桃子"));
	m.insert(make_pair("apple", "苹果"));
	m.insert(make_pair("banana", "香蕉"));
	m.insert(make_pair("pear", "梨子"));
	map<string, string> m1(m);//拷贝构造
	cout << "m1中的元素:" << endl;
	for (auto& e : m1){//范围for遍历
		
		cout << e.first <<"--->"<< e.second << endl;
	}
	cout << endl;

	cout << "m中的元素:" << endl;

	auto it = m.begin();//迭代器方式遍历
	while (it != m.end()){
		cout << it->first << ":" << it->second << endl;
		it++;
	}
	cout <<"apple的count:"<< m.count("apple") << endl;
	cout << "m.size的大小:" << m.size() << endl;//元素个数为4

}
void testMap2(){
	map<string, int> m;
	m["a"] = 100;
	m["b"] = 200;
	m["c"] = 300;//[]当对象中没有匹配的键值对就会插入一个新的键值对

	for (auto& e : m){
		cout << e.first << ":" << e.second << endl;
	}

	cout <<"输出d:"<< m["d"] << endl;//d本来不存在，则插入了一个key为d,value为0的键值对
	m["d"]=400;//修改d的value为400
	for (auto& e : m){
		cout << e.first << ":" << e.second << endl;
	}

}

void testMap3(){
	map<string, int> m3 = {{ "a", 0 },{ "b", 0 },{ "c", 0 } };

	m3.at("a") = 10;
	m3.at("b") = 20;
	m3.at("c") = 30;//at函数也可以通过key找到与其对应的值并修改
	//m3.at("d") = 40;//d不存在，会抛异常
	for (auto& x : m3) {
		cout << x.first << ": " << x.second << endl;
	}
	cout << "测试insert:" << endl;
	auto ret1 = m3.insert(make_pair("d", 40));//要插入的值不存在时，可直接插入
	auto ret2 = m3.insert(make_pair("a", 100));//要插入的值存在时会插入失败
	for (auto& x : m3) {
		cout << x.first << ": " << x.second << endl;
	}
	m3.erase("a");
}

void testMap4(){
	map<string, int> m3 = { { "a", 0 }, { "b", 0 }, { "c", 0 } };

	for (auto& x : m3) {
		cout << x.first << ": " << x.second << endl;
	}
	m3.erase("a");
	cout << "删除元素后："<<endl;
	for (auto& x : m3) {
		cout << x.first << ": " << x.second << endl;
	}
	if (1 == m3.count("a"))
		cout << "a还在" << endl;
	else
		cout << "a被删除了" << endl;

}
int main(){
	//testMap1();
	//testMap2();
	//testMap3();
	testMap4();

	system("pause");
	return 0;
}