#include <iostream>
using namespace std;


class Solution {
public:
    double Power(double base, int exponent) {
        double res = 1, t = base;
        bool neg = false;
        if(exponent < 0){
            neg = true;
            exponent = -exponent;
        }
        while(exponent){
            if(exponent&1) res *= t;
            exponent >>= 1;
            t *= t;
        }
        return neg?1/res:res;
    }
};

int main(){
    cout << Solution().Power(9, 7);
    return 0;
}