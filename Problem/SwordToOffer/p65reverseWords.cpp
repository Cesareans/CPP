#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int pre = 0;
        for(int i = 0 ; i<=s.length(); ++i){
            if(i==s.length() || s[i] == ' '){
                reverse(s.begin()+pre, s.begin() + i);
                pre = i+1;
            }
        }
        return s;
    }
};

int main(){
    cout << Solution().reverseWords("Ii am a student.");
}