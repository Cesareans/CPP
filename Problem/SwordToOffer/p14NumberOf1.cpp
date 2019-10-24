#include <iostream>
using namespace std;
class Solution {
public:
    int NumberOf1(int n) {
        int cnt = 0;
        while(n){
            ++cnt;
            n&=n-1;
        }
        return cnt;
    }
};

int main(){
    cout << Solution().NumberOf1(-2);
    return 0;
}