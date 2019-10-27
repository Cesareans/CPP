#include "header/base.h"
using namespace std;
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }

    int dfs(TreeNode* node){
        if(!node) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        if(l==-1||r==-1)return -1;
        else if(abs(l-r) > 1) return -1;
        else return max(l,r) + 1;
    }
};