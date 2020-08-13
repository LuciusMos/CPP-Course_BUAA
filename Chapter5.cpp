#include <iostream>
using namespace std;
#include <cstdio> /*<stdio.h>*/
//static, const
/*
static: 和作用域相关 
1. static local variable: 保值
2. static global function: 仅本文件可以使用 
3. static data member: 共享内存 
4. static function memeber: Class::Fun
*/ 
/* 
extern int global;//全局变量定义在别的文件A中，可以在除了A的文件中声明
extern void fun1();*/
//link错误：要找找不到；重定义
/*
const:
*/ 
/*
public protected private:
在类外如果想使用类中的成员,只能直接使用public类型的,protected和private都是不能访问的,对于类外使用而言,这两个是完全相同的.
但是在基类的派生类中,可以直接访问继承而来的protected成员,但是不能访问private限制的成员.所以在派生类中,可以访问基类继承而来的public
和proected两种类型的成员.在public公有派生下,继承而来的成员访问权限不变.protected派生下,public和protected都变成protected,private派生
下,所有的继承下来都是private了.
*/ 
void fun3(int i)
{
	i++;
}
class Test
{
public:
	static int i;//属于本类全部对象 
	int j;
public:
	Test(/*int ai, */int aj);
	~Test();
	static void a_fun();
};
int Test::i = 10;//类似全局变量 
/*
static void Test::a_fun()
{
	return;
}*/
Test::Test(int aj)
{
	//this->i = ai;
	this->j = aj;
	cout << "born" << endl;
}
Test::~Test()
{
	cout << "destroy" << endl;
}
void fun()
{
	/*
	static int i = 0;
	//静态局部变量，不在栈区→不会被释放，但是函数外无法访问 
	i++;
	cout << i <<endl;
	*/
	//static Test t;	
}

int g_i;
//若在A文件中写了函数void fun1()，则除A文件之外的文件无法调用此函数fun1() 
/*
程序间的通信：
1. 函数调用
2. 同一类的不同函数：function member, data member
3. 同一类的不同对象：t1, t1
4. global variable 
*/ 
void fun4(const Test *t)//指针所指向的对象是常量 
{
	
} 
//#include <h1.h>
//#include <h2.h>
int main()
{
	/*
	for (int i = 0;i < 3;i++) {
		fun();
	}*/
	
	/*
	static int s_i;
	cout << &g_i << endl;
	cout << &s_i << endl;*/
	//静态变量：只在本区域可访问的全局变量 
	/*
	Test t1(2);
	Test t2(4);*/
	/*
	T1::ABC a;//namespace T1
	T2::ABC b;//namespace T2 */
	int m = 10;
	fun3(m);
	cout << m << endl;
	return 0;
}

