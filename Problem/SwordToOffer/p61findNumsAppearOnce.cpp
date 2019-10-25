#include <vector>
#include "header/base.h"
using namespace std;

class Solution {
public:
    vector<int> findNumsAppearOnce(const vector<int>& nums) {
        int twos = 0;
        for(int i : nums) twos^=i;
        twos &= -twos;
        int a = 0, b = 0;
        for(int i : nums){
            if(i&twos) a^=i;
            else b^=i;
        }
        return {a,b};
    }
};

int main(){
    cout << Solution().findNumsAppearOnce({1,2,3,3,4,4});
}