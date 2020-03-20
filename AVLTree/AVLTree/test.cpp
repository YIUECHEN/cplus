#include"AVLTree.h"

int main(){
	AVLTree<int> t;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a){
		t.Insert(e);
	}	
	t.InOrder();
	//cout << t.LeftMost()->_data << endl;
	//out << t.RightMost()->_data << endl;
	if (t.IsAVLTREE()){
		cout << "ÊÇAVLTree!" << endl;
	}
	else{
		cout << "²»ÊÇAVLTree!" << endl;
	}
	return 0;
}