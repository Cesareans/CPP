#include <memory>
#include <iostream>

using namespace std;

class A{
public:
    A(){
        cout << "A construct." << endl;
    }
    ~A(){
        cout << "A destruct." << endl;
    }
};
template <class T>
class IntellijPtr{
public:
    T * ptr;
    IntellijPtr(T * t){
        ptr = t;
    }
    ~IntellijPtr(){
        delete ptr;
    }
};

int main(){
    A * a = new A();
    IntellijPtr<A> ptr = a;
    return 0;
}