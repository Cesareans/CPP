#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    string replaceSpaces(const string &str) {
        int size = str.length();
        for (char i : str) {
            if (i == ' ') size += 2;
        }
        string res(size,' ');
        for (long i = str.length() - 1, j = size-1; i >= 0&&j>=0; ) {
            if(str[i] == ' '){
                i--;
                res[j--] = '0';
                res[j--] = '2';
                res[j--] = '%';
            }else{
                res[j--] = str[i--];
            }
        }
        return res;
    };
};

int main(){
    cout << Solution().replaceSpaces("We are happy.");
    return 0;
}