#include"BSTree.h"

int main(){
	int array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t;
	for (auto e : array){
		t.Insert(e);
	}

	cout << t.LeftMost()->_data << endl;
	cout << t.RightMost()->_data << endl;
	BSTNode<int>* pCur = t.Find(2);
	if (pCur){
		cout <<"´æÔÚ£¡" << endl;
	}
	else{
		cout << "²»´æÔÚ£¡" << endl;

	}
	t.InOrder();


	t.Delete(8);
	t.Delete(1);
	t.Delete(5);

	t.InOrder();
	system("pause");
	return 0;
}