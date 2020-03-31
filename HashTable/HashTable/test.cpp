#include"HashTable.h"
#include"HashBucket.h"

void test1(){
	HashTable<int> ht;
	ht.Insert(4);
	ht.Insert(7);
	ht.Insert(8);
	ht.Insert(27);
	ht.Insert(9);
	ht.Insert(5);
	ht.Insert(3);
	ht.Insert(1);

	ht.Erase(2);
	ht.Erase(8);

}
void test2(){
	HashBucket<int> hb;
	hb.Insert(0);
	hb.Insert(3);
	hb.Insert(6);
	hb.Insert(7);
	hb.Insert(8);
	hb.Insert(13);
	hb.Insert(33);

	hb.print();
	cout << hb.Size() << endl;
	hb.Erase(33);
	hb.Erase(13);
	hb.print();

	if (hb.Find(13) == nullptr){
		cout << "not find!" << endl;
	}
	hb.Clear();
	cout << hb.Size() << endl;
	hb.print();
}

int main(){
	//test1();
	test2();
	return 0;
}