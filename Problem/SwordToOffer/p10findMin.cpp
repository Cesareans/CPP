#include "header/base.h"

class Solution {
public:
    int findMin(const vector<int>& nums) {
        if(nums.empty()) return -1;
        int l = 0, r = nums.size()-2, back = nums.back();
        while(l < r){
            int mid = (l+r)>>1;
            if(nums[mid] >= back) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};

int main(){
    cout << Solution().findMin({1, 1, 1, 0, 1});
}
