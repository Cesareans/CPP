#include <iostream>
using namespace std;
class Solution {
public:
    int cutRope(int number) {
        int * n = new int[number + 1]();
        n[1] = 1;
        for(int i = 2; i <= number; ++i){
            for(int j = 1; j <= i ; ++j){
                n[i] = max(max(n[i], (i-j) * n[j]), j * (i-j));
            }
        }
        return n[number];
    }
};

int main(){
    cout << Solution().cutRope(8);
}