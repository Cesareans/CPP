#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        unordered_set<int> set;
        vector<int> res;
        for(int i : nums){
            int need = target - i;
            if(set.find(need) != set.end()){
                res.push_back(need);
                res.push_back(i);
            }else{
                set.insert(i);
            }
        }
        return res;
    }
};