#include"BSTree.h"

int main(){
	int array[] = { 2, 5, 3, 4, 1, 7, 9, 6, 8, 0 };
	BSTree<int> t;
	for (auto e : array){
		t.Insert(e);
	}

	cout << t.LeftMost()->_data << endl;
	cout << t.RightMost()->_data << endl;
	BSTNode<int>* pCur = t.Find(2);
	if (pCur){
		cout << pCur->_data << endl;
	}
	system("pause");
	return 0;
}