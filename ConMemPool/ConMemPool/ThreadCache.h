#pragma once
#include"Common.h"
#include"CentralCache.h"
class ThreadCache{
public:
	void* Allocte(size_t size);//������
	void Deallocte(void* ptr,size_t size);//�ͷŻ�����
	void* FetchFromCentralCache(size_t index);//��centralcacheȡ�ڴ�
	//void* ReleaseToCentrealCache(size_t index);//�ͷŻ�centralcache

private:

	FreeList _freeLists[NFREE_LIST];

};

