#include<iostream>
#include<vector>

using namespace std;

void test_Vector1(){
	vector<int> v1;       //无参构造
	vector<int> v2(5, 10);//后面的参数10可以不要

	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(v1);   //拷贝构造

	
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	//遍历
	for (size_t i = 0; i < v1.size(); ++i){
		cout << v1[i] << ' ';
	}
	cout << endl;

	vector<int>::iterator it = v2.begin();
	while (it != v2.end()){
		cout << *it << ' ';
		++it;
	}
	cout << endl;

	for (auto e : v3){
		cout << e<< ' ';
	
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend()){
		cout << *rit << ' ';
		++rit;
	}
	cout << endl;


}


void test_Vector2(){

	vector<int> v1;

	for (size_t i = 0; i <10; ++i){
		v1.push_back(i);
	}
	//resize改变size
	v1.resize(5);

	for (size_t i = 0; i < v1.size(); ++i){
		cout << v1[i] << ' ';//0,1,2,3,4size变为5
	}
	cout << endl;

	v1.resize(10, 100);
	v1.resize(8);

	for (size_t i = 0; i < v1.size(); ++i){
		cout << v1[i] << ' ';//0,1,2,3,4,100,100,100最终size变为8
	}
	cout << endl;

	cout << v1.size() << endl;    //8
	cout << v1.capacity() << endl;//13

}


//capacity按1.5倍增长
void test_Vector3(){
	vector<int> v(5,10);

	size_t sz = v.capacity();
	for (size_t i = 0; i < 100; ++i){
		v.push_back(i);
		if (sz != v.capacity()){
			sz = v.capacity();
			cout << "capacity change : "<< sz << endl;
		}
	}
}

//尾插、尾删
void test_Vector4(){
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	v.pop_back();
	v.pop_back();

	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

//find在一段区间上找某个有效字符，不是vector的接口
//insert在某处插入一个有效字符，原数据后移
//erase删除某处的数据，size减少
//swap
void test_Vector5(){
	vector<int> v;


	for (size_t i = 0; i < 10; ++i){
		v.push_back(i);
	}
	for (auto e : v){
		cout << e << ' ';
	}
	cout << endl;

	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	v.insert(pos, 30);

	cout << v.size() << endl;
	for (auto e : v){
		cout << e << ' ';
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 5);
	v.erase(pos);
	cout << v.size() << endl;
	for (auto e : v){
		cout << e << ' ';
	}
	cout << endl;

	vector<int> swapv;

	swapv.push_back(100);
	cout << "swap:"<<endl;
	for (auto e : swapv){
		cout << e << ' ';
	}
	cout << endl;

	swapv.swap(v);
	for (auto e : swapv){
		cout << e << ' ';
	}
	cout << endl;

	for (auto e : v){
		cout << e << ' ';
	}
	cout << endl;
}




int main(){

	//test_Vector1();
	//test_Vector2();
	//test_Vector3();
	//test_Vector4();
	test_Vector5();


	system("pause");
	return 0;

}

