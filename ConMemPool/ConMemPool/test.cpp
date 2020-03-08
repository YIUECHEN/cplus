#include"ThreadCache.h"
#include<vector>
void UnitThreadCache(){
	ThreadCache tc;
	vector<void*> v;

	for (int i = 0; i < 21; i++){//链表一开始是空的，第一次先从central获取，十九次从链表获取，链表空了以后，再从central获取一次（白盒测试）
		v.push_back(tc.Allocte(7));
	}

	for (int i = 0; i < 21; i++){
		printf("[%d]--->%p\n",i,v[i]);
	}

	for (auto ptr:v){
		tc.Deallocte(ptr, 7);//释放申请出来的内存
	
	}
}
void UnitTestSizeClass(){
	cout << SizeClass::RoundUp(1) << endl;
	cout << SizeClass::RoundUp(127) << endl;
	cout<<endl;

	cout << SizeClass::RoundUp(129) << endl;
	cout << SizeClass::RoundUp(1023) << endl;
	cout << endl;

	cout << SizeClass::RoundUp(1025) << endl;
	cout << SizeClass::RoundUp(8*1024-1) << endl;
	cout << endl;

}
int main(){
	//UnitThreadCache();
	UnitTestSizeClass();

	system("pause");
	return 0;
}