#include <iostream>
#include <vector>

using namespace std;
using UL = unsigned long;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

void printPost(TreeNode *n) {
    if (n == nullptr) return;
    printPost(n->left);
    printPost(n->right);
    cout << n->val << " ";
}

void printMid(TreeNode *n) {
    if (n == nullptr) return;
    printMid(n->left);
    cout << n->val << " ";
    printMid(n->right);
}

void printPre(TreeNode *n) {
    if (n == nullptr) return;
    cout << n->val << " ";
    printPre(n->left);
    printPre(n->right);
}

class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if(pre.size() == 0) return nullptr;
        return reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }

private:
    TreeNode *reConstructBinaryTree(const vector<int> &pre, UL pl, UL pr, const vector<int> &mid, UL ml, UL mr) {
        if (pl > pr || ml > mr) return nullptr;
        UL i;
        for (i = ml; i <= mr; ++i) {
            if (pre[pl] == mid[i]) {
                break;
            }
        }
        auto *midNode = new TreeNode(mid[i]);
        midNode->left = reConstructBinaryTree(pre, pl + 1, pl + i - ml, mid, ml, i - 1);
        midNode->right = reConstructBinaryTree(pre, pl + 1 + i - ml, pr, mid, i + 1, mr);
        return midNode;
    }
};

class StringSolution {
public:
    string getPostSerial(const string &pre, const string &mid) {
        return getPostSerial(pre, 0, pre.length() - 1, mid, 0, mid.length() - 1);
    }

private:
    string getPostSerial(const string &pre, UL pl, UL pr, const string &mid, UL ml, UL mr) {
        if (pr < pl || mr < ml) return "";
        UL i = ml;
        for (; i <= mr; ++i) {
            if (pre[pl] == mid[i])break;
        }
        return getPostSerial(pre, pl + 1, pl + i - ml, mid, ml, i - 1)  +
               getPostSerial(pre, pl + i - ml + 1, pr, mid, i + 1, mr) + mid[i];
    }
};

int main() {
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> mid = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode *node = Solution().reConstructBinaryTree(pre, mid);
    printPost(node);
    cout << endl;
    printMid(Solution().reConstructBinaryTree(pre, mid));
    cout << endl;
    printPre(Solution().reConstructBinaryTree(pre, mid));
    cout << endl;

    cout << StringSolution().getPostSerial("ABDEC", "DBEAC");
    return 0;
}
