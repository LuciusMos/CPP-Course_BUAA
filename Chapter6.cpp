#include <iostream>
using namespace std;
// design pattern 设计模式 
class Scheduler {
	Scheduler() {} // private
	static Scheduler *self;
public:
	static Scheduler *get_instance();
};
Scheduler * Scheduler::self = NULL;//没有static 
Scheduler * Scheduler::get_instance() {
	if (self == NULL) 
		self = new Scheduler();
	return self;
}

//重载运算符 
class Account {
	char *name;
	int id;
	//...
	int balance;
public:
	Account(int money);
	int get_balance();
	void Save(int money);
	Account operator+(int money); //operator-overloading
};
Account::Account(int money) {
	this->balance = money;
}
int Account::get_balance() {
	return this->balance;
}
void Account::Save(int money) {
	this->balance += money;
}
Account Account::operator+(int money) {
	this->balance += money;
	return *this;
}

// const
class Test {
	int i;
public:
	void set_i(int ai) { // inline function内联函数 
		i = ai;
	}
	int get_i() const { // 允许常量对象调用 
		return i;
	}
}; 

int main()
{
	const Test t = *new Test();
	//t.set_i(1);
	cout << t.get_i() << endl; // 若get_i没有const则会报错
	
	/*
	//Account a = *new Account();
	Account a(100);
	//Account a;
	//a = a + 100;
	//a += 100;
	a.Save(100);
	cout << a.get_balance();
	return 0;*/
}
/*
C++: new delete (operators)
C: malloc free (lib functions: stdlib)
new/malloc:
1.预先不知空间大小
2.人为控制生命周期  e.g. this->ac = new AutoAC();
new = malloc + constructor
delete = destructor + free
*/ 
/*
封装
new-delete
opertaor overloading
const (const int *p函数输入输出)
static
copy-constructor reference
constructor(default constructor)-destructor
this.
private/public
from struct to class
*/ 

