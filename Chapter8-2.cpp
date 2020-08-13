#include <iostream>
using namespace std;
//template
//reuse
template <class T>
class Stack {
	T pool[100];
	int top;
public:
	Stack() : top(0) {}
	void Push(T i) {
		//isfull
		pool[top++] = i;
	}
	T Pop() {
		//isempty
		return pool[--top];
	}
}; 
#include <vector>
#include <list>
#include <iterator> 
//1. 万能容器
//2. 动态增长 
int main()
{
	/*
	Stack<int> s;
	for (int i = 0;i < 10;i++) {
		s.Push(i);
	}
	for (int i = 0;i < 10;i++) {
		cout << s.Pop() << endl;
	}*/
	
	
	vector<int> vi;
	for (int i = 0;i < 10000;i++) {
		vi.push_back(i);//调拷贝构造 >10000次（连续空间存储，空间不够时申请新空间并拷贝） 
	}
	//cout << vi[3001] << endl;//运算符重载 []，伪装为数组 
	vector<int>::iterator it = vi.begin();
	while (it < vi.end()) { //重载++ *，伪装为指针 
		cout << *it << endl;
		it++;
	}
	
	/*
	list<int> vi;
	for (int i = 0;i < 10000;i++) {
		vi.push_back(i);//push_back传值，调拷贝构造 10000次 
	}
	list<int>::iterator it = vi.begin();
	while (it != vi.end()) { //重载++ *，伪装为指针 
		cout << *it << endl;
		it++;
	}*/
	return 0;
}
//工厂模式（构建型）
//观察者模式（行为型） 
