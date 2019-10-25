#include <vector>
#include <queue>
#include "header/base.h"
using namespace std;

class Solution {
public:
    vector<int> printFromTopToBottom(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> tq;
        tq.push(root);
        TreeNode * node;
        while (!tq.empty() && (node = tq.front())){
            tq.pop();
            if(node->left) tq.push(node->left);
            if(node->right) tq.push(node->right);
            res.push_back(node->val);
        }
        return res;
    }
};

int main(){
    cout << Solution().printFromTopToBottom(TreeNode::build({2,-1,-1}));
}