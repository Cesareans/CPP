#include <iostream>
#include "header/base.h"
using namespace std;
class Solution {
public:
    bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(!pRoot1) return false;
        return isSubTree(pRoot1, pRoot2) || hasSubtree(pRoot1->left, pRoot2) || hasSubtree(pRoot1->right, pRoot2);
    }

private:
    bool isSubTree(TreeNode* r1, TreeNode * r2) {
        if(!r2 || !r1) return r1||!r2;
        if(r1->val != r2->val) return false;
        return isSubTree(r1->left, r2->left) && isSubTree(r1->right, r2->right) ;
    }
};

int main(){
    Solution().hasSubtree(TreeNode::build({8,8,7,9,2,-1,-1,-1,-1,4,7,-1,-1,-1,-1}), TreeNode::build({8,9,2,-1,-1,-1,-1}));
}