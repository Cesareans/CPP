#include "header/base.h"
class Solution {
public:
    int strToInt(string str) {
        if (str.length() <= 0) return 0;
        bool isPositive = true;
        long res = 0;
        int idx = 0;
        while (str[idx] == ' ') {
            idx++;
            if(idx >= str.length()){
                return 0;
            }
        }
        if (str[idx] == '-') {
            isPositive = false;
            idx++;
        }else if (str[idx] == '+') {
            idx++;
        }
        for (; idx < str.length(); ++idx) {
            char c = str[idx];
            if (c >= '0' && c <= '9') {
                res = res * 10 + c - '0';
                if(res > INT_MAX){
                    return isPositive?INT_MAX:INT_MIN;
                }
            } else {
                break;
            }
        }
        return (isPositive ? 1 : -1) * (int)res;
    }
};