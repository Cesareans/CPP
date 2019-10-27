#include "header/base.h"
class Solution {
public:
    bool isContinuous( vector<int> numbers ) {
        if(numbers.size() <= 0) return false;
        sort(numbers.begin(), numbers.end());
        int i = 0;
        while(!numbers[i]) i++;
        for(int j = i+1 ; j < numbers.size(); ++j){
            if(numbers[j] == numbers[j-1]) return false;
        }
        return (numbers.back() - numbers[i]) <=4;
    }
};