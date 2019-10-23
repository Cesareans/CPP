#include <iostream>
using namespace std;
class Solution {
public:
    int maxProductAfterCutting(int length) {
        int * n = new int[length + 1]();
        n[1] = 1;
        for(int i = 2; i <= length; ++i){
            for(int j = 1; j <= i ; ++j){
                n[i] = max(max(n[i], (i-j) * n[j]), j * (i-j));
            }
        }
        return n[length];
    }
};