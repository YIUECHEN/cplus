#include"RBTree.h"

void test1(){

	RBTree<int> t;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : a)
		t.Insert(e);
	t.Inorder();
	if (t.IsRBTree()){
		cout << "t is RBTree!" << endl;
	}
	else{
		cout << "t is not RBTree!" << endl;
	}
}

void test2(){
	RBTree<int> t;

	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : a)
		t.Insert(e);
	RBTree<int>::iterator it = t.Begin();
	
	while (it!=t.End()){
		cout << *it <<" ";
		++it;
	}
	cout << endl;
}
int main(){
	//test1();
	test2();
	return 0;
}