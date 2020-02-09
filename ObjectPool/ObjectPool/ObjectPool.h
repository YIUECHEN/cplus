//�����ڴ��
#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class T, size_t initNum = 100>
class ObjectPool{
public:
	ObjectPool(){
		_start = (char*)malloc(sizeof(T)*initNum);
		_end = _start + sizeod(T)*initNum;
	}

	//����һ������
	T* New(){

		if (_start == _end){
			_start = (char*)malloc(sizeof(T)*initNum);
			_end = _start + sizeod(T)*initNum;
		}
		//���ڴ�ؿ��ٿռ�
		T* obj = (T*)_start;
		_start += sizeof(T);

		//����ݿռ��ʼ����new��λ���ʽ��
		new(obj)T;//���Ѵ��ڵĿռ���ù��캯�����г�ʼ��
		return obj;
	}

	//�ͷſ��ٳ�ȥ���ڴ�
	void* Delete(T* ptr){
		//�������������������ռ��ϵ���Դ
		ptr->~T();

		//���������У�ǰһ��洢��һ��ĵ�ַ��ͷ��
		*(int*)ptr = _freeList;//ǿת��int*�����ٽ����ã�ͷ�ĸ��ֽڴ洢��ַ
		_freeList = ptr;


	}
private:
	char* _start = nullptr;
	char* _end = nullptr;//�����ڴ��ָ��
	T* _freeList = nullptr;
};

void TestObjectPool(){
	ObjectPool<string> pool;
	string* p1 = pool.New();
	string* p2 = pool.New();

	cout << p1 << endl;
	cout << p2 << endl;

	pool.Delete(p1);
	pool.Delete(p2);

	string* p3 = pool.New();
	string* p4 = pool.New();
	string* p5 = pool.New();

	cout << p3 << endl;
	cout << p4 << endl;
	cout << p5 << endl;

}