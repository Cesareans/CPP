#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using UL = unsigned long;
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        vector<int> vec;
        deque<int> q;
        for(UL i = 0; i < num.size(); ++i){
            while((!q.empty() && num[q.back()] < num[i])) q.pop_back();
            if(!q.empty() && i-q.front() >= size) q.pop_front();
            q.emplace_back(i);
            if(i >= size - 1){
                vec.push_back(num[q.front()]);
            }
        }
        return vec;
    }
};
int main(){
    vector<int> vec = Solution().maxInWindows({1,2,3,1,2,3}, 7);
    for(int i : vec){
        cout << i << " ";
    }

    return 0;
}