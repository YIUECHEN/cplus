#include<iostream>
#include<string>

using namespace std;

void teststring1(){
    string s1;        //string(),����յ�string�����s1
	string s2("hello");//string(const char* s),��c��ʽ�ַ������칹��string�����s2
	string s3(s2);     //string(const string& s),��������s3
	cout << s1 << endl;//strig����֧��cout��cin�������������
	cout << s2 << endl;
	cout << s3 << endl;
}

void teststring2(){
	string s("hello world!");
	cout << s.size() << endl;//12,size��length��һ���ģ���������size
	cout << s.length() << endl;//12
	cout << s.capacity() << endl;//15��������С��16����β�洢��\0
	cout << s<< endl;

	s.clear();//��s�е��ַ�����գ���size��0�����ı�ײ�ռ��С
	cout << s.size() << endl;//0
	cout << s.capacity() << endl;//15
	cout << s << endl;//�޴�ӡ����

	s.resize(15,'a');//����Ч�ַ��������ӵ�15�����ദλ����\0����
	cout << s.size() << endl;//15
	cout << s.capacity() << endl;//15
	cout << s << endl;//15��a

	s.resize(20);//����Ч�ַ��������ӵ�20�������λ�����ַ�a����
	cout << s.size() << endl;//20
	cout << s.capacity() << endl;//31

	s.resize(5);//����Ч�ַ�������С��5�������ı�ײ�ռ��С
	cout << s.size() << endl;//5
	cout << s.capacity() << endl;//31
	cout << s << endl;//5��a

}

void teststring3(){
	string s("hello");

	s.reserve(100);//reserve����ı���Ч�ַ��ĸ�����
	cout << s.size() << endl;//5
	cout << s.capacity() << endl;//111

	s.reserve(50);//reserve����С��string�ĵײ�ռ��Сʱ�����Ὣ�ռ���С
	cout << s.size() << endl;//5
	cout << s.capacity() << endl;//111

}

void testPushBack(){
	string s;
	int count=0;
	//s.reserve(100);��������
	size_t sz = s.capacity();
	cout << "making s grow:" << endl;
	for (int i = 0; i < 100; ++i){
		s.push_back('c');
		if (sz != s.capacity()){//4������
			count++;
			sz = s.capacity();
			cout << "capacity changed:"<<sz<< '\n';
		}
	}
	cout << count << endl;
}

void TestString()
{
	string s1("hello Bit");
	const string s2("Hello Bit");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;
	s1[0] = 'H';
	cout << s1 << endl;
	//s2[0] = 'h'; //�������ʧ�ܣ���Ϊconst���Ͷ������޸�
}

void TestString1(){//3�ֱ���
	string s("hello");

	//1.for�±�+operator[]
	for (size_t i = 0; i < s.size(); ++i){
		cout << s[i]<<' ';
	}
	cout << endl;

	//2.������(˳�����)
	string::iterator it = s.begin();
	while (it != s.end()){
		cout << *it<<' ';
		++it;
	}
	cout << endl;

	//��������������������
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend()){
		cout << *rit <<' ';
		++rit;
	}
	cout << endl;
	
	//3.��Χfor

	for (auto ch : s){
		cout << ch<<' ';
	}
	cout << endl;

}


void TestString2(){
	string s("hello");
	s.push_back(' ');   //��s������ַ��ո�
	s.append("world");  //��s����ַ���world
	s += "hello";      //��s��׷���ַ���hello
	s += "cap";        //��s��׷���ַ���cap
	cout << s << endl;
	cout << s.c_str() << endl;//��c���Եķ�ʽ��ӡ

	size_t pos = s.find(' ');//find�ҵ��ַ��ո�����λ�ò�����
	cout << pos << endl;
	string ret = s.substr(pos, s.size() - pos);//substr��ȡ�����ϵ��ַ��������أ�����ҿ���
	cout << ret << endl;

	s.erase(0,pos+1);//����ҿ���+1��ո�Ҳ��ɾ��
	cout <<s << endl;

}



int main(){
	//teststring1();
	//teststring2();
	//teststring3();
	//testPushBack();
	//TestString();
	//TestString1();
	TestString2();


	system("pause");
	return 0;
}