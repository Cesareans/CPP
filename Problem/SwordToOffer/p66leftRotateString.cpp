#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string leftRotateString(string str, int n) {
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + str.size() - n);
        reverse(str.begin() + str.size() - n, str.end());
        return str;
    }
};

int main(){
    cout << Solution().leftRotateString("abcdefg", 2);
}
