#include <memory>
#include <iostream>
#include <vector>
using namespace std;
class B;

class A {
public:
    virtual void func(){
        cout << "A.func" << endl;
    }
    ~A() {
        cout << "A Destructor" << endl;
    }
};

class B : public A{
public:
    void func() override{
        cout << "B.func" << endl;
    }
    ~B(){
        cout << "B Destructor" << endl;
    }
};

int main(){
    shared_ptr<A> a = make_shared<B>();
    a->func();
    shared_ptr<B> b = dynamic_pointer_cast<B>(a);
    b->func();
}