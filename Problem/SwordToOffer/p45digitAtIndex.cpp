#include <cmath>
class Solution {
public:
    int digitAtIndex(int n) {
        return (n/(int)pow(10,n))%10;
    }
};