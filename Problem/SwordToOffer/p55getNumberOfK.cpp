#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int getNumberOfK(const vector<int>& nums , int k) {
        if(nums.empty()) return 0;
        int ll,rr,l = 0,r = nums.size() - 1;
        while(l < r){
            int mid = (l+r)>>1;
            if(nums[mid] >= k) r = mid;
            else l = mid+1;
        }
        if(nums[l] != k) return 0;
        ll = l, l = 0,r = nums.size() - 1;
        while(l < r){
            int mid = (l+r+1)>>1;
            if(nums[mid] <= k) l = mid;
            else r = mid-1;
        }
        rr = l;
        return rr-ll + 1;
    }
};

int main(){
    cout << Solution().getNumberOfK({1,2,3,4}, 5);
}