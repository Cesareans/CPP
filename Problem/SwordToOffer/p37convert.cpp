#include "header/base.h"
#include <iostream>
using namespace std;

class Solution {
public:
    TreeNode* convert(TreeNode* root) {
        return pass(root).left;
    }

private:
    TreeNode pass(TreeNode* node){
        TreeNode res(0);
        if(!node) return res;
        TreeNode ld = pass(node->left);
        TreeNode * mid = node;
        TreeNode rd = pass(node->right);
        res.left = ld.left;
        res.right = rd.right;
        if(ld.right) ld.right->right = mid;
        else res.left = mid;
        if(rd.left) rd.left->left = mid;
        else res.right = mid;
        mid->left = ld.right;
        mid->right = rd.left;

        return res;
    }
};

int main(){
    Solution().convert(TreeNode::build({10, 6, 14, 4, 8, 12, 16}));
}