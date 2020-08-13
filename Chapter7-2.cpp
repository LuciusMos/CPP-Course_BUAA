#include <iostream>
using namespace std;
class Pet
{
protected: // 子类可访问，对外为私有 
	int age;
	char *name;
public:
	Pet(int aage, char *aname)
	{
		this->age = aage;
		this->name = aname;
	}
	void Speak() {
		cout << "speak" << endl;
	}
};

class Cat : public Pet//类内默认私有，若没有public则为私有继承（维护语法完整性），父类公有函数在子类中会变为私有 
{
	int type;
public:
	Cat(int aage, char *aname, int atype) : Pet(aage, aname), type(atype)//父类构造，成员构造 
	//若不说明则寻找父类默认构造 
	{
		this->type = atype;
	}
	void Speak() { //redefination
		Pet::Speak(); //JAVA: super.Speak();
		cout << "miao" << endl;
	}
};

class Test{
public:
	int i;
	int j;
public:
	Test(int a) : j(a), i(j) //执行顺序为类内声明顺序 
	{
	}
};

class Base1{
public:
	void f() {
	}
	void h() {
	}
};
class Base2{
public:
	void h() {
	}
	void f() {
	}
};
/*class Derived : public Base1, public Base2 { //多重继承 
};*/ 
class Derived : public Base1 { //规避多重继承 
	Base2 b2;
public:
	void h() {
		b2.h();
	}
};

int main()
{
	/*Cat c(1, "dudu", 3);
	c.Speak();*/
	/*Test t(3);
	cout << t.i << " " << t.j << endl;*/
	Derived d;
	d.f();
	d.h();
	return 0;
}

