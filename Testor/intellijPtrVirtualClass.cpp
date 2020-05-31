#include <iostream>
#include <memory>
using namespace std;
class IA{
public:
    virtual void func(){
        cout << " IA. Func ";
    };
};

class A : public IA{

public:
    void func() override {
        cout << " A. Func ";
    }
};

void f(const A& a){
    shared_ptr<IA> ia = make_shared<IA>(a);
    ia->func();
}
int main(){
    A a;
    f(a);
    return 0;
}

