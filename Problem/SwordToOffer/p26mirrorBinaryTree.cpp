#include "header/base.h"
#include <iostream>
using namespace std;

class Solution {
public:
    void mirror(TreeNode* root) {
        if(root == nullptr) return;
        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }
};