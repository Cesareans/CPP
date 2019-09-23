#include <iostream>
using namespace std;
class A{
public:
    int * p;
    A(){
        cout<<"A construct" << endl;
    }
};

int main(){
    // Default initialization : call default constructor only
    A a;
    printf("%p\n", a.p);
    // Value initialization = Zero initialization + Default initialization
    // Zero initialization : initialize all fields to zero.
    A a1{};
    printf("%p\n", a1.p);


    return 0;
}