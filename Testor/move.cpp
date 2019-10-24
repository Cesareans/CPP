#include <iostream>
#include <vector>
using namespace std;

class A{
public:
    A(){
        cout << "A constructor" << endl;
    }
    A(const A& a){
        cout << "A copy constructor" << endl;
    }
//    A(A&& a){
//        cout << "A transfer constructor" << endl;
//    }
    ~A(){
        cout << "A destructor" << endl;
    }
};
int main(){
    vector<A> vec;
    A a = A();
    vec.push_back(a);
    vec.push_back(move(A()));
    return 0;
}