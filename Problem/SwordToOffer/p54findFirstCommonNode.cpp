#include "header/base.h"
using namespace std;
/*
 * 不同部分为a， 和b，公共部分为c；a + c + b = b + c + a;让两个一起走，a走到头就转向b， b走到头转向a，则在公共部分相遇
 */
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        auto p = headA, q = headB;
        while(p != q){
            if(p) p = p->next;
            else p = headB;
            if(q) q = q->next;
            else q = headA;
        }
        return p;
    }
};