#include <vector>
using namespace std;

class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        if(array.empty()) return false;
        int h = array.size(), w = array[0].size();
        int i = h-1,j=0;
        while(i >= 0 &&  j < w ){
            if(target == array[i][j]){
                return true;
            }else if(target > array[i][j]){
                ++j;
            }else{
                --i;
            }
        }
        return false;
    }
};

int main(){
    return Solution().searchArray({{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,10,15}}, 5);
}