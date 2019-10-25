#include <vector>
using namespace std;

class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        int sum = nums.size();
        for(int i = 0 ; i < nums.size(); ++i){
            sum = sum + i - nums[i];
        }
        return sum;
    }
};