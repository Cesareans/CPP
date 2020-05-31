#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int x = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
const int N = 110;

const int dx[3] = {1, 0, 1}, dy[3] = {0, 1, 1};

int dfs(char maze[N][N], string s, int sy, int sx, int idx, int dir){
    if(idx >= s.length()) return 1;
    if(maze[sy+dy[dir]][sx+dx[dir]] == s[idx]){
        return dfs(maze, s, sy+dy[dir], sx+dx[dir], idx + 1, dir);
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int h, w;
        cin >> h >> w;
        char maze[N][N];
        memset(maze, 0, sizeof(maze));
        for(int i = 1; i <= h ; ++i)
            for(int j = 1 ; j <= w; ++j)
                cin >> maze[i][j];
        string s;
        cin >> s;
        int res = 0;
        for(int i = 1; i <= h ; ++i){
            for(int j = 1 ; j <= w; ++j){
                if (maze[i][j] == s[0]) {
                    for(int k = 0 ; k < 3 ; ++k){
                        res += dfs(maze, s, i, j, 1, k);
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
