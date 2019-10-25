class Solution {
public:
    static int sum, idx;
    Solution(){
        ++Solution::idx;
        Solution::sum += Solution::idx;
    }
    static void reset(){
        sum = 0;
        idx = 0;
    }
    int Sum_Solution(int n) {
        Solution::reset();

        Solution* s = new Solution[n];
        delete[] s;

        return Solution::sum;
    }
};
int Solution::sum = 1;
int Solution::idx = 1;

int main(){
    return Solution().Sum_Solution(10);
}