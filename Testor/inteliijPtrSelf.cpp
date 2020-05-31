#include <memory>
#include <iostream>
#include <vector>
using namespace std;
class B;

class A {
public:
    virtual void func(){
        cout << "A.func" << endl;
    }
    ~A() {
        cout << "A Destructor" << endl;
    }
};

int main(){
    assert(false);
    return 0;
}