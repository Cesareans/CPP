#include <vector>
#include <queue>
#include "header/base.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> tq;
        TreeNode * node, *sentry = new TreeNode(0);
        tq.push(root);
        tq.push(sentry);
        vector<int> level;
        bool rev = false;
        while (!tq.empty() && (node = tq.front())){
            tq.pop();
            if(node==sentry){
                if(rev) reverse(level.begin(), level.end());
                res.push_back(level);
                level.clear();
                rev = !rev;
                if(!tq.empty()) tq.push(sentry);
            }else{
                if(node->left) tq.push(node->left);
                if(node->right) tq.push(node->right);
                level.push_back(node->val);
            }
        }
        return res;
    }
};