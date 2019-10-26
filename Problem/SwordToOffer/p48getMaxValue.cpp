#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution {
public:
    int getMaxValue(const vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int h = grid.size(), w = grid[0].size();
        int ** arr = new int*[h + 1];
        for(int i = 0 ; i <= h; ++i) arr[i] = new int[w + 1]();
        for(int i = 1 ; i <= h; ++i){
            for(int j = 1 ; j <= w ; ++j){
                arr[i][j] = max(arr[i][j-1], arr[i-1][j])+grid[i-1][j-1];
            }
        }
        return arr[h][w];
    }
};
// 线性优化
class Solution1 {
public:
    int getMaxValue(const vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        vector<int> arr(w+1,0);
        for(int i = 1 ; i <= h; ++i){
            for(int j = 1 ; j <= w ; ++j){
                arr[j] = max(arr[j], arr[j-1])+grid[i-1][j-1];
            }
        }
        return arr[w];
    }
};
int main(){
    cout << Solution1().getMaxValue({{2,3,1}});
}