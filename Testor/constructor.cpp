#include <iostream>
using namespace std;

class A {
public:
	A() {
		cout << "A()" << endl;
	}
	A(int i) {
		cout << "A(" << i << ")\n";
	}

private:
	A(const A& a){
	    cout << "Copy constructor" << endl;
	}
};

class B : public A {
public:
	B() {

	}
	B(int i) : A(i) {

	}
};

int  main() {
	B* b = new B(1);
	B* b1 = new B();
	A a;
}