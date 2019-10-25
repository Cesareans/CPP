#include <vector>
#include <climits>
using namespace std;

using UL = unsigned long;
class Solution {
public:
    int maxDiff(vector<int>& nums) {
        int m = INT_MAX, res = 0;
        for(UL i = 0 ; i < nums.size() ; ++i){
            m = min(m , nums[i]);
            res = max(res, nums[i] - m);
        }
        return res;
    }
};