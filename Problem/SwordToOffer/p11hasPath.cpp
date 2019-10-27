#include "header/base.h"

class Solution {
public:
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

    bool hasPath(vector<vector<char>> &matrix, string str) {
        if (str.empty()) return true;
        if (matrix.empty()) return false;
        int h = matrix.size(), w = matrix[0].size();
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (str[0] == matrix[i][j]) {
                    if (dfs(matrix, str, j, i, 1))return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &matrix, const string &str, int x, int y, int idx) {
        if(idx >= str.size()) return true;
        char t = matrix[y][x];
        matrix[y][x] = 0;
        int h = matrix.size(), w = matrix[0].size();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < w && ny >= 0 && ny < h && matrix[ny][nx] == str[idx]){
                if(dfs(matrix, str, nx,ny,idx+1)) return true;
            }
        }
        matrix[y][x] = t;
        return false;
    }
};


int main(){
//    vector<vector<char>> matrix = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
//    cout << Solution().hasPath(matrix, "ABCB");

    vector<vector<char>> matrix1 = {{'A','A'}};
    cout << Solution().hasPath(matrix1, "AAA");
}
