#include <iostream>
using namespace std;
//class OO
//1.everything is an object
//2.封装、继承、多态 
//access control访问控制 
class Student//封装 
{
	//attribute属性 
private://可省略，默认为private  struct默认为public 
	int age; 
	char* name;
	//...
	//method action
public:
	void init(char* a_name,int a_age);//函数不占runtime memory 
	int get_age();
};//程序（机器码）加载到内存中（只读），runtime memory运行期内存 
//never pass by value
/*
void init_student(int age, char* name, Student* s) //自定义类型传递指针 
{
	s->name = name;
	s->age = age;
}
*/
void Student::init(char* a_name,int a_age) //:: = 的 
{
    this->name = a_name;
	this->age = a_age;	
}
int Student::get_age()
{
	cout<< this <<endl;
	return age;
	//return this->age; 
}
#pragma pack(1)//按 1字节对齐
struct Test
{
	double d;
	int i;
	char c1;
	char c2;
};
int main(int argc, char* argv[])
{
	Student s1,s2;
	//init_student(20, "zhang", &s);
	s1.init("zhang",20);
	s2.init("wang",22);
	//cout<<s.name<<endl;
	//cout<<sizeof(Student)<<endl;//默认按大对齐(int 4Byte,char 1Byte) 
	cout<<&s1<<endl;
	cout<<s1.get_age()<<endl;
	cout<<&s2<<endl;
	cout<<s2.get_age()<<endl;//隐藏默认this指针，相当于传递Student* s 
	
	//指针的存在导致可以修改对象的私有变量 
	Student s;
	s1.init("li",20);
	int *p = (int*)&s;
	*p = 30;
	cout<<s.get_age()<<endl;
	return 0;
}

