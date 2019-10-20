#include <iostream>
using namespace std;
class A{
public:
    int a = 1;
    A(){
        cout << a;
    }
};

class B : public A{
public:
    int b;
    B(int ai){
        cout << a;
    }
};

int main(){
    A a;
    return 0;
}