#include <iostream>
using namespace std;

class A{
public:
    int a;

    A* operator&(){
        return 0;
    }
    const A* operator&() const{
        return this;
    }
};

int main(){
    A a{};
    cout << &a << endl;
    const A ac{};
    cout << &ac << endl;
    return 0;
}