#include <vector>
#include <iostream>
#include <climits>
using namespace std;

using UL = unsigned long;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int sum = nums[0], m = sum;
        for(UL i = 1; i < nums.size(); ++i){
            sum = max(sum+nums[i], nums[i]);
            m = max(m, sum);
        }
        return m;
    }
};