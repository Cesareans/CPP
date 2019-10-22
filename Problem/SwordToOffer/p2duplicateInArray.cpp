#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int duplicateInArray(const vector<int> &nums) {
        int l = 1, r = nums.size(), lc, rc;
        while (l < r - 1) {
            int mid = (l + r) / 2;
            lc = rc = 0;
            for (int i = 0; i <= nums.size(); ++i) {
                if (nums[i - 1] >= l && nums[i - 1] <= r) {
                    if (nums[i - 1] < mid) lc++;
                    else rc++;
                }
            }
            if (lc > rc) r = mid;
            else l = mid;
        }
        return l;
    }
};

int main() {
    return Solution().duplicateInArray({2, 3, 5, 4, 3, 2, 6, 7});
}