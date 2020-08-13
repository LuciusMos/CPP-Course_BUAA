#include <iostream>
using namespace std;
/*
指针的错误：
1.fly pointer (=NULL   函数传指针if(p == NULL) return)
2.重复delete/free 
3.bitwise copy (e.g. memcpy明确不会因为指向同一空间而产生错误)
4.return address of local variable
5.memory leak
*/ 
//pass by value vs. pass by address(pointer reference)
void fun1(int i)
{
	i++;
}
void fun2(int *i)
{
	(*i)++;
}
void fun3(int &i) //java: everything is a reference
{
	i++;
}

class Test
{
	int i;
	int *j;
public:
	Test(int a,int b);
	//copy constructer
	//给函数传值时，也会用拷贝构造
	//bitwise copy/浅拷贝(默认) vs. logical copy/深拷贝 
	Test(Test &t);//自己写深拷贝，传引用！ 
	~Test();
};//类后边要有; 
Test::Test(int a,int b)
{
	i = a;
	j = new int(b);
}
Test::Test(Test &t)//深拷贝：copy value, not address 
{
	this->i = t.i;
	this->j = new int(*t.j);//*t.j:*(t.j)
}
Test::~Test()
{
	delete j;
}

int main()
{
	//reference  引用是一个安全的指针
	int i = 10;
	int j = 20;
	int *p;
	p = &i;
	p = &j;
	
	int &r = i;//&:引用符 有一个对int的引用 
	r++;//可认为r和i保持一致 
	cout << i << endl;//i = 11
	r = j;//i = 20
	cout <<  i << endl;
	//解决两个不安全的问题：1.野指针 2.指针指向内容可变
	
	int m = 10;
	fun1(m);
	cout << m << endl;//m = 10
	fun2(&m); 
	cout << m << endl;//m = 11
	fun3(m);
	cout << m << endl;//m = 12 
	
	Test t1(1,2);
	Test t2(t1);//拷贝构造 copy constructer 
	//t2先消亡 
	return 0;
	if (p != NULL) free(p); 
}

