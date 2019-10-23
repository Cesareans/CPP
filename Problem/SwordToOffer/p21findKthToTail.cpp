#include "header/base.h"
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        int length = 0;
        ListNode * node = pListHead;
        while(node!=nullptr){
            ++length;
            node = node->next;
        }
        if(k > length) return nullptr;
        node = pListHead;
        for(int i = 0 ; i < length - k; ++i) node = node->next;
        return node;
    }
};