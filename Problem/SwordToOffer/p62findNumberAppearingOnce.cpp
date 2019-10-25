#include <vector>
using namespace std;

class Solution {
public:
    int findNumberAppearingOnce(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i : nums) {
            ones = (ones^i)&~twos;
            twos = (twos^i)&~ones;
        }
        return ones;
    }
};