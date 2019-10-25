#include <vector>
#include "header/base.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> findPath(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        vector<int> vec;
        dfs(res, vec, root, 0, sum);
        return res;
    }

private:
    void dfs(vector<vector<int>>& res, vector<int>& vec, TreeNode * node, int sum, int target){
        vec.push_back(node->val);
        sum += node->val;
        if(!node->left&&!node->right&&sum == target) res.push_back(vec);
        if(node->left) dfs(res, vec, node->left, sum, target);
        if(node->right) dfs(res, vec, node->right, sum, target);
        vec.pop_back();
    }
};