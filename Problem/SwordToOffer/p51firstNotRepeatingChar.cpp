#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    char firstNotRepeatingChar(string s) {
        unordered_map<char,int> map;
        for(int i = 0 ; i < s.length(); ++i) map[s[i]] += 1;
        for(char i : s){
            if(map[i] == 1){
                return i;
            }
        }
        return '#';
    }
};