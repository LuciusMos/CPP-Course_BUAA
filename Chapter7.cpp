#include <iostream>
using namespace std;
//inheritance¼Ì³Ð
class Borrower {
	int id;
	char *name;
public:
	void borrow();
	//void returnback();
}; 
void Borrower::borrow() {
	cout << "swipe card" <<endl;
}

class Teacher : public Borrower {
public:
	void borrow();
};
void Teacher::borrow() {
	Borrower::borrow();
	cout << "5 books" << endl;
}

int main()
{
	Teacher t;
	t.borrow();
	return 0;
}

