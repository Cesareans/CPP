#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> nums) {
        int num = 0, times = 0;
        for(int i = 0 ; i < nums.size(); ++i){
            if(times == 0){
                num = nums[i];
            }
            times += num == nums[i] ? 1 : -1;
        }
        times = 0;
        for(int i = 0 ; i < nums.size(); ++i){
            times += num == nums[i] ? 1 : 0;
        }
        return times > nums.size() / 2.0 ? num : 0;
    }
};

int main(){
    cout << Solution().MoreThanHalfNum_Solution({2,2,2,2,2,1,3,4,5});
}
