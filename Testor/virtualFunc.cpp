#include <iostream>
#include <typeinfo>
using namespace std;
class A {
public:
    virtual void ai() {
        cout << "a.ai" << endl;
    }
    virtual void bi() {
        cout << "a.bi" << endl;
    }
    void func(){
        cout << "a.func" << endl;
    }
};
class B : public A {
public:
    virtual void bi() {
        cout << "b.bi" << endl;
    }
};

int main(){
    A * a = nullptr;
    // func直接存储了函数的地址
    a->func();
    // ai记录adj与ptr需要通过a指针进行偏移寻址
    a->ai();
    return 0;
}