#include <iostream>
using namespace std;

class A{
    virtual void func(){};
};
class B : public A{};
int main(){
    cout << sizeof(A) << " " << sizeof(B) << endl;
    A a;
    A a1;
    printf("%p %p\n", &a, &a1);
    printf("%ld", &a - &a1);
    return 0;
}