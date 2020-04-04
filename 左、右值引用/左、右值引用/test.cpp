#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
using namespace std;

//int main(){
//	//a是左值：可以被修改的对象
//	//10是右值：通常是常量，a+b,100
//	int a = 10;
//	int b = a;
//}

#if 0
//传参数使用，引用变量与引用实体指向的是同一块内存空间
void swap(int& a,int& b){
	int temp = a;
	a = b; 
	b = temp;
}
int main(){
	int a = 10;
	int b = 20;
	swap(a, b);
	return 0;
}
#endif


#if 0
int add(int a, int b){
	return a + b;
}

int main(){
	//右值引用
	const int&& ra = 10;
	//引用函数返回值，函数返回值是一个临时变量，为右值
	int&& rep = add(10, 20);
	return 0;
}
#endif

#if 0
int main(){
	// 普通类型引用只能引用左值，不能引用右值
	int a = 10;

	int& b = a;
	//int& c = 10;  error:10是右值

	const int& c = 10;
	const int& d = a; //const引用既可引用左值，也可引用右值。

	return 0;
}
#endif

#if 0
int main(){
	//右值引用
	int&& a = 10;  //10是纯右值，没有具体空间；右值引用a在定义的过程中编译器产生了一个临时变量，a实际引用的是临时变量	
	a = 100;

	int b = 10;
	//int&& c = b;error：右值引用不能让引用左值
	//const int&& c = b; 也不可以

	int&& c = (move(b));

	return 0;

}
#endif



#if 0
class Person
{
public:
	Person(char* name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}

	Person(const Person& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}

	/*Person(Person&& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}*/



	Person(Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}


private:
	string _name;
	string _sex;
	int _age;
};
Person GetTempPerson()//表达式的运行结果是一个临时变量或对象，认为是右值
{
	Person p("prety", "male", 18);
	return p;
}
int main()
{
	Person pe(GetTempPerson());//调用右值引用的构造函数
	return 0;
}


#endif


class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

		String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}

	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		return strRet;
	}

	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};
int main()
{
	String s1("hello");
	String s2("world");
	String s3(s1 + s2);
	return 0;
}