#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    priority_queue<int> maxHeap;
    priority_queue<int> minHeap;
    void Insert(int num){
        if(!minHeap.empty() && num > -minHeap.top()){
            maxHeap.push(-minHeap.top());
            minHeap.pop();
            minHeap.push(-num);
        }else{
            maxHeap.push(num);
        }

        if(maxHeap.size() >= minHeap.size() + 2){
            minHeap.push(-maxHeap.top());
            maxHeap.pop();
        }
    }

    double GetMedian(){
        return maxHeap.size() == minHeap.size()? (maxHeap.top()-minHeap.top()) / 2.0 : maxHeap.top();
    }
};
int main(){
    int arr[] = {5,2,3,4,1,6,7,0,8};
    Solution solution;
    for(int i : arr){
        solution.Insert(i);
        cout << solution.GetMedian() << " ";
    }
    return 0;
}