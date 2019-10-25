#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int getNumberSameAsIndex(const vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while (l < r){
            int mid = (l+r)>>1;
            if(nums[mid] >= mid) r = mid;
            else l = mid + 1;
        }
        return nums[l]==l?l:-1;
    }
};

int main(){
    cout << Solution().getNumberSameAsIndex({-3, -1, 1, 4, 5});
}