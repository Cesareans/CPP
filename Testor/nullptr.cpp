#include <iostream>
using namespace std;

class A{
public:
    void func(){
        cout << "A.func()";
    }
};
int main(){
    A * a = nullptr;
    a->func();

    return 0;
}