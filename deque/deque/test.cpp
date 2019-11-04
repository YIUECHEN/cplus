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

//测试构造函数
void testdeque1()
{
	deque<int> d1;//构造空的双端队列

	deque<int> d2(5,10);////用5个值为10的元素构造双端队列
	printdeque(d2);

	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	deque<int> d3(array, array + sizeof(array) / sizeof(array[0]));//用数组的区间构造双端队列
	printdeque(d3);

	deque<int> d4(d2);//用拷贝构造
	printdeque(d4);
}

//测试deque中的迭代器
void testdeque2()
{
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));

	//利用正向迭代器打印d中的元素
	for (deque<int>::iterator it = d.begin(); it < d.end(); ++it){
	
		cout << *it << " ";
	}
	cout << endl;
	
	//利用反向迭代器打印d中的元素

	for (auto rit = d.rbegin(); rit < d.rend(); ++rit){
		cout << *rit << " ";
	
	}
	cout << endl;
}

//测试deque相关容量、修改操作
void testdeque3()
{
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
	printdeque(d);

	//头插尾插、任意位置插入
	//auto it = d.begin() + 3;
	d.push_back(6);
	d.push_front(8);
	d.insert(d.begin(),10);
	printdeque(d);//10,8，0，1，2，3，4，5，6，7，8，9，6
	cout << d.size() <<" "<< d.front()<<" " << d.back() << endl;//13,10,6

	//头删尾删、任意位置删除
	d.pop_back();
	d.pop_front();
	d.erase(d.begin());
    printdeque(d);//0，1，2，3，4，5，6，7，8，9
	cout << d.size() << " " << d.front() << " " << d.back() << endl;// 10,0,9

	//将d中元素清空
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

/*当对deque排序时，需要多次对deque中的元素进行整体遍历，而
deque中的元素整体遍历时效率比较低，这是因为deque底层的空间不连续，如果要进行整体遍历，在某段空间的
默认或首部时，必须要计算下一段或者前一段空间的位置，导致deque的效率比较底下。*/
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