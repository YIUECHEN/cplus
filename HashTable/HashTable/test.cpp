#include"HashTable.h"


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

int main(){
	test1();
}