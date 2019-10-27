#include "header/base.h"

class Solution {
public:
    vector<int> numberOfDice(int n) {
        vector<vector<int>> dp(n+1, vector<int>(6*n+1));
        dp[0][0] = 1;
        for(int i = 1 ; i <= n; ++i)
            for(int j = 1; j <= 6*n; ++j)
                for(int k = 1 ; k <= min(j,6) ; ++k)
                    dp[i][j] += dp[i-1][j-k];
        vector<int> res;
        for(int i = n ; i <= 6*n ; ++i) res.push_back(dp[n][i]);
        return res;
    }
};

int main(){
    cout << Solution().numberOfDice(1);
    cout << Solution().numberOfDice(2);
}
