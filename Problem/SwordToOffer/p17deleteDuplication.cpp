#include <iostream>
#include "header/base.h"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplication(ListNode* head){
        ListNode* node, *dummy = new ListNode(0), *preNode = dummy;
        dummy->next = node = head;
        bool equal;
        while(node!=nullptr){
            equal = false;
            while(node->next!=nullptr&&node->next->val == node->val){
                node->next = node->next->next;
                equal = true;
            }
            if(equal) {
                preNode->next = node->next;
            }else{
                preNode = preNode->next;
            }
            node = node->next;
        }
        return dummy->next;
    }
};