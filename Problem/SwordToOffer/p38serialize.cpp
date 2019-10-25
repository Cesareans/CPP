#include "header/base.h"
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> tq;
        TreeNode * node, * sentry = new TreeNode(0);
        tq.push(root);
        tq.push(sentry);
        bool allEmpty = true;
        while (true){
            node = tq.front();
            tq.pop();
            if(node==sentry){
                if(allEmpty) break;
                allEmpty = true;
                tq.push(sentry);
            }else if(node){
                tq.push(node->left);
                tq.push(node->right);
                if(node->left || node->right) allEmpty = false;
                res += std::to_string(node->val);
                res += ",";
            }else{
                res += "null,";
            }
        }
        res.erase(res.cend()-1);
        return res;
    }

    TreeNode* deserialize(string data) {

    }

};

int main(){
    cout << Solution().serialize(TreeNode::build({8, 12, 2, -1, -1, 6, 4, -1, -1, -1, -1}));
}