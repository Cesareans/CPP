#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        unordered_map<char, int> map;
        int pre = 0, maxLen = 0;

        for(int i = 0 ; i < s.length(); ++i){
            auto iter = map.find(s[i]);
            if(iter != map.end() && iter->second >= pre){
                maxLen = max(maxLen, i-pre);
                pre = iter->second+1;
            }
            map[s[i]] = i;
        }
        if(!maxLen) maxLen = s.length();
        return maxLen;
    }
};
int main(){
    cout<<Solution().longestSubstringWithoutDuplication("abcd");
    cout<<Solution().longestSubstringWithoutDuplication("chbmmcg");
}