/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* L1, ListNode* L2) {
        struct ListNode* dummyHead = new ListNode(0),
            *curr = dummyHead,
            *p = L1,
            *q = L2;

     int carry = 0;

    while(p || q) {
      int x = p ? p->val : 0;
      int y = q ? q->val : 0;
      int sum = x + y + carry;
      carry = sum / 10;
      curr->next = new ListNode( sum % 10 );

      if(p) p = p->next;
      if(q) q = q->next;

      curr = curr->next;
    }

    if(carry>0) curr->next = new ListNode(carry);

    return dummyHead->next;
    }
};
