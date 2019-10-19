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
    int * ai = reinterpret_cast<int*>(a);
    cout << ai;

    return 0;
}