#include"RBTree.h"

int main(){

	RBTree<int> t;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : a)
		t.Insert(e);
	t.Inorder();
	if (t.IsRBTree()){
		cout << "t is RBTree!" << endl;
	}
	else{
		cout << "t is not RBTree!"<<endl;
	}
	return 0;
}