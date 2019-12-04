#include<iostream>
#include<map>
#include<string>
using namespace std;


void testMap1(){
	map<string, string> m;
	m.insert(pair<string, string>("peach", "����"));
	m.insert(make_pair("apple", "ƻ��"));
	m.insert(make_pair("banana", "�㽶"));
	m.insert(make_pair("pear", "����"));
	map<string, string> m1(m);//��������
	cout << "m1�е�Ԫ��:" << endl;
	for (auto& e : m1){//��Χfor����
		
		cout << e.first <<"--->"<< e.second << endl;
	}
	cout << endl;

	cout << "m�е�Ԫ��:" << endl;

	auto it = m.begin();//��������ʽ����
	while (it != m.end()){
		cout << it->first << ":" << it->second << endl;
		it++;
	}
	cout <<"apple��count:"<< m.count("apple") << endl;
	cout << "m.size�Ĵ�С:" << m.size() << endl;//Ԫ�ظ���Ϊ4

}
void testMap2(){
	map<string, int> m;
	m["a"] = 100;
	m["b"] = 200;
	m["c"] = 300;//[]��������û��ƥ��ļ�ֵ�Ծͻ����һ���µļ�ֵ��

	for (auto& e : m){
		cout << e.first << ":" << e.second << endl;
	}

	cout <<"���d:"<< m["d"] << endl;//d���������ڣ��������һ��keyΪd,valueΪ0�ļ�ֵ��
	m["d"]=400;//�޸�d��valueΪ400
	for (auto& e : m){
		cout << e.first << ":" << e.second << endl;
	}

}

void testMap3(){
	map<string, int> m3 = {{ "a", 0 },{ "b", 0 },{ "c", 0 } };

	m3.at("a") = 10;
	m3.at("b") = 20;
	m3.at("c") = 30;//at����Ҳ����ͨ��key�ҵ������Ӧ��ֵ���޸�
	//m3.at("d") = 40;//d�����ڣ������쳣
	for (auto& x : m3) {
		cout << x.first << ": " << x.second << endl;
	}
	cout << "����insert:" << endl;
	auto ret1 = m3.insert(make_pair("d", 40));//Ҫ�����ֵ������ʱ����ֱ�Ӳ���
	auto ret2 = m3.insert(make_pair("a", 100));//Ҫ�����ֵ����ʱ�����ʧ��
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
	cout << "ɾ��Ԫ�غ�"<<endl;
	for (auto& x : m3) {
		cout << x.first << ": " << x.second << endl;
	}
	if (1 == m3.count("a"))
		cout << "a����" << endl;
	else
		cout << "a��ɾ����" << endl;

}
int main(){
	//testMap1();
	//testMap2();
	//testMap3();
	testMap4();

	system("pause");
	return 0;
}