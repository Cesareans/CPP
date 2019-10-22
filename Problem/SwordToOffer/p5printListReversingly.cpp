#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<int> printListReversingly(ListNode *head) {
        vector<int> vec;
        stack<int> s;
        while(head!=nullptr){
            s.push(head->val);
            head = head->next;
        }
        vec.reserve(s.size());
        while(!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
        return vec;
    }
};