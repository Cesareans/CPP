#include "header/base.h"
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode * res = head, * pre = head->next, * q = pre;
        res->next = nullptr;
        while (pre!=nullptr){
            q = pre->next;
            pre->next = res;
            res = pre;
            pre = q;
        }
        return res;
    }
};



int main(){
    ListNode * head = ListNode::build({1,2,3,4});
    cout << head;
    ListNode * node = Solution().reverseList(head);
    cout << head;
    cout << node;
    return 0;
}