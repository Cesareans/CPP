#include <iostream>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        double res = 1, t = 1;
        bool neg = false;
        if(exponent < 0){
            neg = true;
            exponent = -exponent;
        }
        while(exponent){
            t *= base;
            if(exponent&1)res *= t;
            exponent >>= 1;
        }
        return neg?1/res:res;
    }
};

int main(){
    cout << Solution().Power(2.4, -1);
    return 0;
}