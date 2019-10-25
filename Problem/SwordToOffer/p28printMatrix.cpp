#include <vector>
#include <climits>
#include "header/base.h"
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int h = matrix.size(), w = matrix[0].size(), s = w*h;
        res.reserve(w*h);

        int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1}, x = 0, y = 0, dir = 0;
        for(int i = 0; i < s;++i){
            res.push_back(matrix[y][x]);
            matrix[y][x] = INT_MIN;
            int cnt = 0;
            while((x+dx[dir]<0 || x+dx[dir] >=w || y+dy[dir]<0||y+dy[dir]>=h || matrix[y+dy[dir]][x+dx[dir]]==INT_MIN) && cnt <=4){
                dir = (dir+1)%4;
                cnt ++;
            }
            x += dx[dir];
            y += dy[dir];
        }
        return res;
    }
};

int main(){
    cout << Solution().printMatrix({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
}