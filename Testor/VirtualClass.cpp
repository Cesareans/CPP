#include <iostream>

using namespace std;

class A {
public:
    virtual void func() = 0;
};

class B : public A {
public:
    void func() override {
        cout << "B.func()" << endl;
    }
};

int main() {
    //A a; // Wrong
    //A a[100]; // Wrong
    B b;
    A&a = b;
    a.func();
    return 0;
}