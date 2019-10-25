#include "header/base.h"
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode(0), * node = head;
        while(l1!= nullptr && l2!= nullptr){
            if(l1->val > l2->val){
                node->next = l2;
                l2 = l2->next;
            }else{
                node->next = l1;
                l1 = l1->next;
            }
            node = node->next;
        }
        node->next = l1== nullptr?l2:l1;
        return head->next;
    }
};

int main(){
    cout<<Solution().merge(ListNode::build({1,3,5,7}), ListNode::build({2,4,6,8,10}));
    cout<<Solution().merge(nullptr, ListNode::build({2,4,6,8,10}));
    cout<<Solution().merge(nullptr, nullptr);
    return 0;
}