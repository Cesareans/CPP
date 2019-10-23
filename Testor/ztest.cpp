#include <iostream>
#include <bitset>
using namespace std;

int main(){
    int i = -2;
    cout << bitset<sizeof(int) * 8>(i & i-1);

    return 0;
}