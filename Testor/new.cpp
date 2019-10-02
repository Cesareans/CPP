#include <iostream>
using namespace std;

class A{
public:
    int i = 0;
    A() {
        i = 1;
        cout << "A construct" << endl;
    }
};
int main(){
    A a;
    cout << a.i << endl;
    a.i = 199;
    cout << a.i << endl;
    A* a1 = new(&a)A;
    cout << a.i << endl;
    cout << a1->i << endl;

    return 0;
}