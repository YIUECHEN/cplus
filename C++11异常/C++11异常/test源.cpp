#include<iostream>
using namespace std;



//double Div(int n, int m){
//	if (m == 0){
//		throw "��������Ϊ0!";
//	}
//	else{
//		return n / m;
//	}
//}
//void fun(){
//	int n, m;
//	cin >> n >> m;
//	try{
//		Div(n, m);
//	}
//	catch (const char* errmsg){
//		cout << errmsg << endl;
//	}
//	//cout << Div(n, m) << endl;�׳����쳣���������catch
//}
//int main(){
//	try{
//		fun();
//	}
//	catch (const char* errmsg){
//		cout << errmsg << endl;
//	}	
//	catch(...){
//		cout << "δ֪�쳣��" << endl;
//	}
//	return 0;
//}


double Div(int n, int m){
	if (m == 0){
		throw "��������Ϊ0!";
	}
	else{
		return n / m;
	}
}
void fun(){
	int* array = new int[10];
	int n, m;
	cin >> n >> m;
	try{
		Div(n, m);
	}
	catch (...){

		cout << "delete[]" << endl;
		delete[] array;
		throw;
	}
	cout << "delete[]" << endl;
	delete[] array;
}
int main(){
	try{
		fun();
	}
	catch (const char* errmsg){
		cout << errmsg << endl;
	}
	catch (...){
		cout << "δ֪�쳣��" << endl;
	}
	return 0;
}