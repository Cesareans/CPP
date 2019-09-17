#include <iostream>

using namespace std;

class Ref {
public:
    void f() {
        cout << "Ref f" << endl;
    }
};

class RefField {
private:
    Ref &r;

public:
    RefField(Ref& ref) : r(ref) {}

    void f(){
        cout<<"RefField f"<<endl;
        r.f();
    }
};

int main() {
    Ref r;
    Ref& r1 = r;
    RefField rf(r);
    rf.f();
    return 0;
}