#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
using namespace std;

//int main(){
//	//a����ֵ�����Ա��޸ĵĶ���
//	//10����ֵ��ͨ���ǳ�����a+b,100
//	int a = 10;
//	int b = a;
//}

#if 0
//������ʹ�ã����ñ���������ʵ��ָ�����ͬһ���ڴ�ռ�
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
	//��ֵ����
	const int&& ra = 10;
	//���ú�������ֵ����������ֵ��һ����ʱ������Ϊ��ֵ
	int&& rep = add(10, 20);
	return 0;
}
#endif

#if 0
int main(){
	// ��ͨ��������ֻ��������ֵ������������ֵ
	int a = 10;

	int& b = a;
	//int& c = 10;  error:10����ֵ

	const int& c = 10;
	const int& d = a; //const���üȿ�������ֵ��Ҳ��������ֵ��

	return 0;
}
#endif

#if 0
int main(){
	//��ֵ����
	int&& a = 10;  //10�Ǵ���ֵ��û�о���ռ䣻��ֵ����a�ڶ���Ĺ����б�����������һ����ʱ������aʵ�����õ�����ʱ����	
	a = 100;

	int b = 10;
	//int&& c = b;error����ֵ���ò�����������ֵ
	//const int&& c = b; Ҳ������

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
Person GetTempPerson()//���ʽ�����н����һ����ʱ�����������Ϊ����ֵ
{
	Person p("prety", "male", 18);
	return p;
}
int main()
{
	Person pe(GetTempPerson());//������ֵ���õĹ��캯��
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