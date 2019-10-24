#include <iostream>
#include <vector>
using namespace std;

class A {
public:
	A() {
		cout << "A()" << endl;
	}
	A(int i) {
		cout << "A(" << i << ")\n";
	}
	virtual void func(){
	    cout << "A.func" << endl;
	}

private:
	A(const A& a){
	    cout << "Copy constructor" << endl;
	}
};

class B : public A {
public:
    virtual void func(){
        cout << "B.func" << endl;
    }
	B() {
        func();
	}
	B(int i) : A(i) {

	}
};

class C {
private:
    C(){};
};

int  main() {
	B* b = new B(1);
	B* b1 = new B();
	A a;

}