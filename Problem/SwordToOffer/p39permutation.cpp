#include <vector>
#include "header/base.h"
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permutation(vector<int>& nums) {
        vector<vector<int>> vec;
        permutation(vec, nums, 0);
        return vec;
    }

private:
    void permutation(vector<vector<int>>& vec, vector<int>& nums, int idx){
        if(idx == nums.size() - 1){
            vec.push_back(nums);
            return;
        }
        unordered_set<int> set;
        for(int i = idx; i < nums.size(); ++i){
            if(set.find(nums[i]) == set.end()){
                swap(nums[idx], nums[i]);
                permutation(vec, nums, idx + 1);
                swap(nums[i], nums[idx]);
                set.insert(nums[i]);
            }
        }
    }
};

int main(){
    vector<int> vec={1,1,3};
    Solution().permutation(vec);
}