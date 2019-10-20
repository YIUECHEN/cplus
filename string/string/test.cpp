#include<iostream>
#include<string>

using namespace std;

void teststring1(){
    string s1;        //string(),构造空的string类对象s1
	string s2("hello");//string(const char* s),用c格式字符串构造构造string类对象s2
	string s3(s2);     //string(const string& s),拷贝构造s3
	cout << s1 << endl;//strig对象支持cout和cin进行输出和输入
	cout << s2 << endl;
	cout << s3 << endl;
}

void teststring2(){
	string s("hello world!");
	cout << s.size() << endl;//12,size和length是一样的，更建议用size
	cout << s.length() << endl;//12
	cout << s.capacity() << endl;//15。容量大小是16，结尾存储了\0
	cout << s<< endl;

	s.clear();//将s中的字符串清空，将size清0，不改变底层空间大小
	cout << s.size() << endl;//0
	cout << s.capacity() << endl;//15
	cout << s << endl;//无打印内容

	s.resize(15,'a');//将有效字符个数增加到15个，多处位置用\0补充
	cout << s.size() << endl;//15
	cout << s.capacity() << endl;//15
	cout << s << endl;//15个a

	s.resize(20);//将有效字符个数增加到20个，多出位置用字符a补充
	cout << s.size() << endl;//20
	cout << s.capacity() << endl;//31

	s.resize(5);//将有效字符个数缩小到5个，不改变底层空间大小
	cout << s.size() << endl;//5
	cout << s.capacity() << endl;//31
	cout << s << endl;//5个a

}

void teststring3(){
	string s("hello");

	s.reserve(100);//reserve不会改变有效字符的个数，
	cout << s.size() << endl;//5
	cout << s.capacity() << endl;//111

	s.reserve(50);//reserve参数小于string的底层空间大小时，不会将空间缩小
	cout << s.size() << endl;//5
	cout << s.capacity() << endl;//111

}

void testPushBack(){
	string s;
	int count=0;
	//s.reserve(100);不会扩容
	size_t sz = s.capacity();
	cout << "making s grow:" << endl;
	for (int i = 0; i < 100; ++i){
		s.push_back('c');
		if (sz != s.capacity()){//4次扩容
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
	//s2[0] = 'h'; //代码编译失败，因为const类型对象不能修改
}

void TestString1(){//3种遍历
	string s("hello");

	//1.for下标+operator[]
	for (size_t i = 0; i < s.size(); ++i){
		cout << s[i]<<' ';
	}
	cout << endl;

	//2.迭代器(顺序遍历)
	string::iterator it = s.begin();
	while (it != s.end()){
		cout << *it<<' ';
		++it;
	}
	cout << endl;

	//反向迭代器（逆序遍历）
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend()){
		cout << *rit <<' ';
		++rit;
	}
	cout << endl;
	
	//3.范围for

	for (auto ch : s){
		cout << ch<<' ';
	}
	cout << endl;

}


void TestString2(){
	string s("hello");
	s.push_back(' ');   //在s后插入字符空格
	s.append("world");  //在s后加字符串world
	s += "hello";      //在s后追加字符串hello
	s += "cap";        //在s后追加字符串cap
	cout << s << endl;
	cout << s.c_str() << endl;//用c语言的方式打印

	size_t pos = s.find(' ');//find找到字符空格所在位置并返回
	cout << pos << endl;
	string ret = s.substr(pos, s.size() - pos);//substr截取区间上的字符串并返回（左闭右开）
	cout << ret << endl;

	s.erase(0,pos+1);//左闭右开，+1后空格也会删除
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