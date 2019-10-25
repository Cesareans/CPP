#include <vector>
#include "header/base.h"
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int> queue;
        for(int i : input){
            if(queue.size() < k){
                queue.push(i);
            }else if(queue.top() > i){
                queue.pop();
                queue.push(i);
            }
        }
        vector<int> res(k, 0);

        while(!queue.empty()){
            res[--k]=queue.top();
            queue.pop();
        }
        return res;
    }
};

int main(){
    cout << Solution().getLeastNumbers_Solution({1,2,3,4,5,6,7,8}, 4);
}