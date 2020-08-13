#include <iostream> //stdio
using namespace std;
//function:
//1.overloading重载/过载：同名函数，不同（个数、类型、顺序）参数 
void Print(int i)
{
	cout << i << endl; 
}
void Print(const char* str) //允许函数重名，过载 
{
	cout << str << endl;
}
//2.default parameter默认参数
//函数体body,definition
//2.5头文件包括函数的声明（a.c  a.h） 对于默认参数，声明与函数体中只能定义一次 
//void fun(int a, int b=20, int c=10);
void fun(int a, int b=20, int c=10)//调用者不传递c时默认c为10
{                                  //默认的参数必须在后边 
	cout << a << " " << b << " " << c << endl;
}//127.0.0.1 本机IP地址
//3.占位符 
void fun2(int)//参数可以没有名字（int是占位参数），但调用时必须传入 
{
	//更大的可能性是overloading，用来区分不同函数 
}
//C语言知识
//1.function callback函数指针  https://blog.csdn.net/str999_cn/article/details/78591369
//2.指针pointer   .malloc
//3.数组array
//4.结构体struct
//5.宏macro
//三类：①常量宏：消除神仙数magic number  
#define PI 3.14
#define STU_COUNT 100
//②函数宏：小函数频繁调用（调用函数需要保存现场恢复现场）
#define ADD(a,b) (a+b)
//③控制宏：开关
#define REMOTE_VER
//6.头文件 
#include "AHeader.h"//可能会被重复包含
#include "AHeader.h" 
int main(int argc, char* argv[])
{
	//overloading
	Print(1);
	Print("hello");
	//default parameter
	fun(1,2,3);
	fun(1,2);
	fun(1,20,3);//只想传入参数1 3，但仍需要抄参数2 
	fun2(1);//必须传入一个int 
#ifdef REMOTE_VER
	cout << "connect oracle" << endl;//控制宏 
#else
	cout << "connect mysql" <<endl;
#endif	
	return 0;
}
//生成可执行文件：编译+链接（ERR：找不到/多了） 
//extern "C" void c_fun(); 告诉链接器此函数为C函数 
