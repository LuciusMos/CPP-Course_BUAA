#include <iostream>
using namespace std;
class Pet {
protected:
	int age;
	char *name;
public:
	//虚函数表v-table(一个类一个)，存储所有 
	/*virtual void Speak() { //（1）virtual虚函数 
		cout << "speak" << endl;
	}*/
	virtual void Speak() = 0;//pure(=0) virtual function
	//如果一个类有纯虚函数，那么这个类为抽象类（不可实例化） 
	/*
	1. reuse, upcasting
	2. 纲领，子类必须实现该函数 
	3. 串联 
	*/
};
/*
虚函数：子类可以重写，为了允许用基类的指针来调用子类的函数 
纯虚函数 ：由子类实现，“接口继承” 
普通函数： 强制实现，子类不应该重写 
*/

/*
静态类型：对象在声明时采用的类型，在编译期既已确定；
动态类型：通常是指一个指针或引用目前所指对象的类型，是在运行期决定的；
静态绑定：绑定的是静态类型，所对应的函数或属性依赖于对象的静态类型，发生在编译期；
动态绑定：绑定的是动态类型，所对应的函数或属性依赖于对象的动态类型，发生在运行期；
*/
 
class Cat : public Pet {
public:
	void Speak() { //virtual自动继承 
		cout << "miao" << endl;
	}
};

class Dog : public Pet {
public:
	void Speak() {
		cout << "wang" << endl;
	}
};
#include <memory.h>
void Needle(Pet& pet) { //（2）v-ptr赋初值由构造函数隐式完成，传值则会拷贝构造，故此处必须传引用    
	                    //never pass by value 大，不能回写，会调拷贝构造 
	//binding绑定:将函数的一次调用，与函数入口相对应的过程
	//early binding前绑定（默认） 
	//late binding/runtime binding/dynamic binding
	/*Dog dog;
	memcpy(&pet, &dog, 4);*/
	pet.Speak();
}

class FlyObject { //接口，没有数据成员的抽象类（强调行为共性）
public:
	virtual void fly() = 0;//串联 
};

class Machine {
};
class Airplane : public Machine, public FlyObject {
public:
	void fly() {
	}
};
 
class Animal {
};
class Bird : public Animal, public FlyObject  {
public:
	void fly() {
	}
};

void Scan(FlyObject& flyer) {}


int main()
{
	//upcasting向上类型转换，多态的前提 
	//Cat cat;
	//Needle(cat);
	
	//cout << sizeof(Pet) << endl;
	//12Byte: +4Byte  virtual function，但与个数无关
	//多态的实现：每个对象都有虚指针v-ptr指向类的虚函数表v-table 
	
	/*Cat c1, c2;
	int *p = (int *)&c1;
	cout << *p << endl;
	p = (int *)&c2;
	cout << *p << endl;*/
	
	//Pet p; //[Error] cannot declare variable 'p' to be of abstract type 'Pet', 
	               //because the following virtual functions are pure within 'Pet'
	//构造
	//析构：父类virtual修饰，防止部分释放 
	return 0;
}

