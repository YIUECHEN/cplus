#include<deque>
#include<iostream>
#include <algorithm>

using namespace std;

void printdeque(const deque<int> d)
{
	for (auto e : d){
		cout << e<<" ";
	}
	cout <<endl;
}

//���Թ��캯��
void testdeque1()
{
	deque<int> d1;//����յ�˫�˶���

	deque<int> d2(5,10);////��5��ֵΪ10��Ԫ�ع���˫�˶���
	printdeque(d2);

	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	deque<int> d3(array, array + sizeof(array) / sizeof(array[0]));//����������乹��˫�˶���
	printdeque(d3);

	deque<int> d4(d2);//�ÿ�������
	printdeque(d4);
}

//����deque�еĵ�����
void testdeque2()
{
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));

	//���������������ӡd�е�Ԫ��
	for (deque<int>::iterator it = d.begin(); it < d.end(); ++it){
	
		cout << *it << " ";
	}
	cout << endl;
	
	//���÷����������ӡd�е�Ԫ��

	for (auto rit = d.rbegin(); rit < d.rend(); ++rit){
		cout << *rit << " ";
	
	}
	cout << endl;
}

//����deque����������޸Ĳ���
void testdeque3()
{
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
	printdeque(d);

	//ͷ��β�塢����λ�ò���
	//auto it = d.begin() + 3;
	d.push_back(6);
	d.push_front(8);
	d.insert(d.begin(),10);
	printdeque(d);//10,8��0��1��2��3��4��5��6��7��8��9��6
	cout << d.size() <<" "<< d.front()<<" " << d.back() << endl;//13,10,6

	//ͷɾβɾ������λ��ɾ��
	d.pop_back();
	d.pop_front();
	d.erase(d.begin());
    printdeque(d);//0��1��2��3��4��5��6��7��8��9
	cout << d.size() << " " << d.front() << " " << d.back() << endl;// 10,0,9

	//��d��Ԫ�����
	d.clear();
	cout << d.size() << endl;//0



}

void testdequeSort()
{
	int array[] = { 5,8,3,9,2,0,1,3,7};
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
	printdeque(d);

	sort(d.begin(), d.end());
	printdeque(d);

/*����deque����ʱ����Ҫ��ζ�deque�е�Ԫ�ؽ��������������
deque�е�Ԫ���������ʱЧ�ʱȽϵͣ�������Ϊdeque�ײ�Ŀռ䲻���������Ҫ���������������ĳ�οռ��
Ĭ�ϻ��ײ�ʱ������Ҫ������һ�λ���ǰһ�οռ��λ�ã�����deque��Ч�ʱȽϵ��¡�*/
}

int main()
{
    //testdeque1();
	//testdeque2();
	//testdeque3();
	testdequeSort();
	system("pause");
	return 0;

}