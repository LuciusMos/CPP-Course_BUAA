#include <iostream>
using namespace std;
//封装 
//constructor,destructor,copy constructor 
class Student
{
	int age;
	char* name;
	//...
public:
	Student (int aage,char* aname);//constructor构造函数 赋初值
	int get_age() {
		return this->age;
	} 
};

Student::Student(int aage,char* aname)
{
	this->age = aage;
	this->name = aname;
}

class Test
{
	int i;
	int *j;
	//属性一定是数据成员
	//数据成员中可能包含非必然属性 
public:
	//Type1 
	Test(int ai);
	Test(int ai,int aj);
	//Type2
	//Test(int ai,int aj=0);
	//-Which is better? -The first one!
	//performance
	void clean();
	~Test();//destructor析构函数（只会有一个，不会重载） 
	//析构函数在对象消亡时清理堆区内存 
	//构造中有new，就一定要有析构函数。
	//构造中没有new，也可能需要析构函数。 
};
Test::Test(int ai)
{
	this->i = ai;//只有这一个语句时会出错 原因：delete野指针时程序会崩溃 默认构造Test()也必须要给j赋值为NULL 
	this->j = NULL; 
}
Test::Test(int ai,int aj)
{
	i = ai;
	j = new int(aj);//int's constructor
	//int i = 10;
	//int i(10);
}
void Test::clean()
{
	delete j;
}
Test::~Test()
{
	delete j;
}

class Test2
{
	int i;
	int j;
public:
	Test2();
	Test2(int a1);
	Test2(int a1,int a2);
};

class StudyGroup
{
	Student s1;//小组中含有学生的value 
	Student *s2;//小组中含有学生的Handle，学生不是必然组成部分 
	//出发点：节省空间 sizeof(Student) vs. 4B 
};

int main()
{
	Student s(10,"zhang");
	//cout << s.get_age() << endl;
	Test2 t4();//this is a function declaration!
	Test r1(1,2);//局部变量r1在stack，8B；其中4B指向heap的4B的int
	Test *p = new Test(1,2);//p in stack；8B & 4B in heap  p->i p->*j j->aj 
	delete p;//清理i,*j,(j->aj) 
	return 0;
}
/*
程序分区：
静态 常量   e.g.代码区  大小不可变
Runtime：stack局部变量 heap动态分配变量  (global全局变量区) 
Student q;//stack
Student* p = new Student;//heap
*/
/*
创建对象的两种方法：
1. 在栈上创建对象（Objects on the Stack)
   ClassName ObjName1；
   ClassName ObjName2(parameter01) // But never ObjName() 
2. 在堆上创建对象（Objects on the Heap）
   ClassName *obj1 = new ClassName();
   ClassName *obj2 = new ClassName(parameter);
   delete obj1;
   delete obj2;
*/
