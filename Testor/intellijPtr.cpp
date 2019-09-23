#include <memory>
#include <iostream>

using namespace std;
class B;

class A {
public:
    shared_ptr<B> pb;
    ~A() {
        cout << "A Destructor" << endl;
    }
};

class B{
public:
    shared_ptr<A> pa;
    ~B(){
        cout << "B Destructor" << endl;
    }
};
int main() {
    shared_ptr<B> spb = make_shared<B>();
    shared_ptr<A> spa = make_shared<A>();
    spb->pa = shared_ptr<A>(spa);
    // spa->pb = shared_ptr<B>(spb);

    return 0;
}