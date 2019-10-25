#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double sqrt5 = sqrt(5);
int x = [](){
    cout << "External function" << endl;
    return 0;
}();
int fib(int n){
    return round(sqrt5/5 * (pow((1+sqrt5)/2,n) - pow((1-sqrt5)/2,n)));
}

int main(){
    for(int i = 0 ; i < 10 ; ++i){
        cout << fib(i) << endl;
    }
    return 0;
}