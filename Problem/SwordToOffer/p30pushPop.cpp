#include <vector>
#include <stack>
#include <iostream>
#include "header/base.h"
using namespace std;
class Solution {
public:
    bool isPopOrder(vector<int> pushV, vector<int> popV) {
        if(pushV.size() != popV.size()) return false;
        stack<int> s;
        int idx = 0;
        for(int i : pushV){
            s.push(i);
            while (!s.empty() && popV[idx] == s.top()){
                s.pop();
                idx++;
            }
        }
        return s.empty();
    }
};

int main(){
    cout << Solution().isPopOrder({1,2,3,4,5}, {4,5,3,2,1});
    cout << Solution().isPopOrder({1,2,3,4,5}, {4,5,3,2,1});
}