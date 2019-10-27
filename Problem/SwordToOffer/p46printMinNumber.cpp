#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    string printMinNumber(const vector<int> &nums) {
        vector<string> vec;
        vec.reserve(nums.size());
        for (int i : nums) vec.emplace_back(to_string(i));
        sort(vec.begin(), vec.end(), [](const string& s1, const string& s2){
            return s1+s2<s2+s1;
        });
        string res;
        for (const string &s:vec)res += s;
        return res;
    }
};

int main(){
    cout << Solution().printMinNumber({3,32,321});
    cout << Solution().printMinNumber({});
}