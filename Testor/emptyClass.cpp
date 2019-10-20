#include <iostream>
using namespace std;

class A{
    void func(){};
};
class B : public A{};
class C : virtual public A{
    virtual void fun(){};
};
int main(){
    cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(C) <<endl;
    A a;
    A a1;
    printf("%p %p\n", &a, &a1);
    printf("%ld", &a - &a1);
    return 0;
}