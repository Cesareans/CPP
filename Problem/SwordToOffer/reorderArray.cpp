#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for(int i = 0,j=array.size()-1;i<j;++i,--j){
            while(array[i]%2==1&&i<j) ++i;
            while(array[j]%2==0)--j;
            swap(array[i], array[j]);
        }
    }
};

int main(){
    vector<int> vec = {1,2,3,4,5,6};
    Solution().reOrderArray(vec);
    for(int i : vec){
        cout << i << " ";
    }
}