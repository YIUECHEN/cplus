#include"AVLTree.h"

int main(){
	AVLTree<int> t;
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto e : a){
		t.Insert(e);
	}	
	t.InOrder();
	//cout << t.LeftMost()->_data << endl;
	//out << t.RightMost()->_data << endl;
	if (t.IsAVLTREE()){
		cout << "��AVLTree!" << endl;
	}
	else{
		cout << "����AVLTree!" << endl;
	}
	return 0;
}