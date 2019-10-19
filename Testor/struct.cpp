#include <iostream>
using namespace std;

struct A{
    int a;
};

struct B : public A{
    int b;
};

int main(){
    B b;
    cout << b.a;
    return 0;
}