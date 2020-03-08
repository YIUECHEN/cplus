#include"CentralCache.h"


//从page cache获取一个span
Span* CentralCache::GetOneSpan(size_t size){
	size_t index = SizeClass::ListIndex(size);
	SpanList& spanlist = _spanLists[index];
	Span* it = spanlist.Begin();
	while (it != spanlist.End()){
		if (!it->_freelist.Empty()){
			return it;
		}
		else{
			it = it->_next;
		}
	}

	//page cache获取一个span
	size_t numpage = SizeClass::NumMovePage(size);
	Span* span = pageCacheInst.NewSpan(numpage); 
	return span;
}

size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t size){
	Span* span = GetOneSpan(size);
	FreeList& freelist = span->_freeList;
	size_t actualNum = freelist.PopRange(start, end, num);
	span->_usecount += actualNum;

	return actualNum;
	
}


//将一定数量的对象释放到span跨度
void CentralCache::ReleaseListToSpans(void* start, size_t size){}

