#include <memory>
#include <iostream>
#include <vector>
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

class D{
public:
    D(){}
    ~D() {
        cout << "D Destructor" << endl;
    }
};
int main() {
    shared_ptr<B> spb = make_shared<B>();
    shared_ptr<A> spa = make_shared<A>();
    spb->pa = shared_ptr<A>(spa);
    // spa->pb = shared_ptr<B>(spb);

    vector<unique_ptr<D>> vec;
    for(int i = 0 ; i < 10 ; ++i){
        unique_ptr<D> au(new D());
        cout << au.get();
        vec.push_back(move(au));
        cout << au.get();
        cout << vec[i].get();
    }

    cout << "??";

    while (1);
    return 0;
}