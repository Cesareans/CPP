#include <iostream>
using namespace std;

const int N = 100000;
int arr[N];
int x = [](){
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    return 0;
}();
int climbStairs(int n){
    if(n == 1) return 0;
    if(!arr[n]) arr[n] = climbStairs(n-2) + climbStairs(n-3);
    return arr[n];
}
void climbStairsPath(int n){

}

int main(){
    int n = 10;
    for(int i = 1 ; i < n ; ++i){
        cout << climbStairs(i) << " ";
    }
    return 0;
}