#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int duplicateInArray(const vector<int> &nums) {
        int *ni = new int[nums.size()]();
        int res = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0 || nums[i] >= nums.size()){
                res = -1;
                break;
            }else if(ni[nums[i]] != 0) {
                if(res < 0){
                    res = nums[i];
                }
            } else {
                ni[nums[i]]++;
            }
        }
        return res;
    }
};

int main(){
    return Solution().duplicateInArray({52, 35, 51, 77, 19, 10, 27, 37, 54, 26, 75, 9, 71, 81, 76, 75, 21, 100, 54, 50, 87, 40, 21, 87, 18, 23, 58, 12, 17, 84, 11, 6, 91, 73, 57, 19, 85, 65, 36, 44, 40, 77, 33, 56, 27, 48, 77, 59, 8, 65, 77, 13, 9, 52, 53, 9, 77, 73, 85, 33, 31, 10, 84, 94, 4, 13, 82, 12, 91, 89, 93, 40, 42, -100, 85, 36, 20, 33, 13, 48, 38, 93, 30, 87, 47, 44, 29, 47, 33, 52, 36, 55, 20, 29, 68, 58, 64, 5, 15, 26});
}