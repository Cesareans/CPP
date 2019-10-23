#include "header/base.h"
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    ListNode *entryNodeOfLoop(ListNode *head) {
        unordered_set<ListNode> set;
        ListNode * node = head;
        while (node != nullptr){
            set.insert(node);

        }
    }
};