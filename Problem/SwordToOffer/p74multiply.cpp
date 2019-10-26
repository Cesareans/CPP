#include "header/base.h"
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<int> res(n, 1);
        for(int i = 1, p = 1; i < n; ++i){
            p*=A[i-1];
            res[i] = p;
        }
        for(int i = n-2, p = 1; i >= 0; --i){
            p*=A[i+1];
            res[i] *= p;
        }
        return res;
    }
};

int main(){
    cout << Solution().multiply({1,2,3,4,5});
    return 0;
}