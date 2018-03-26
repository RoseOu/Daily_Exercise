// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(0), *p=l1, *q=l2, *k = new ListNode(0);
        int c=0,i=0,num;
        while( p!=NULL && q!=NULL){
            if(i==0){
                num = p->val + q->val + c;
                if(num > 9){
                    l3->val = num%10;
                    c=1;
                }else{
                    l3->val = num;
                    c=0;
                }
                k=l3;
                i++;
            }else{
                num = p->val + q->val + c;
                ListNode *ln = new ListNode(num%10);
                if(num > 9){
                    c=1;
                }else{
                    c=0;
                }
                k->next = ln;
                k = k->next;
            }
            p = p->next;
            q = q->next;
        }
        while(p!=NULL){
            num = p->val + c;
            ListNode *ln = new ListNode(num%10);
            if(num > 9){
                c=1;
            }else{
                c=0;
            }
            k->next = ln;
            k = k->next;
            p = p->next;
        }
        while(q!=NULL){
            num = q->val + c;
            ListNode *ln = new ListNode(num%10);
            if(num > 9){
                c=1;
            }else{
                c=0;
            }
            k->next = ln;
            k = k->next;
            q = q->next;
        }
        if(c==1){
            ListNode *ln = new ListNode(c);
            k->next = ln;
            k = k->next;
        }
        return l3;
    }
};
