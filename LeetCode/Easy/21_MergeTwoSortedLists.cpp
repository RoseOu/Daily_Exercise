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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2){
            return NULL;
        }else if(!l1){
            return l2;
        }else if(!l2){
            return l1;
        }
        ListNode *l3=new ListNode(l1->val);
        ListNode *lr=l3;
        if(l1->val<=l2->val){
            l3->val=l1->val;
            l1=l1->next;
        }else{
            l3->val=l2->val;
            l2=l2->next;
        }
        while(l1&&l2){
            if(l1->val<=l2->val){
                ListNode *lp=new ListNode(l1->val);
                lr->next=lp;
                lr=lr->next;
                l1=l1->next;
            }else{
                ListNode *lp=new ListNode(l2->val);
                lr->next=lp;
                lr=lr->next;
                l2=l2->next;
            }
        }
        if(!l1){
            while(l2){
                ListNode *lp=new ListNode(l2->val);
                lr->next=lp;
                lr=lr->next;
                l2=l2->next;
            }
        }
        if(!l2){
            while(l1){
                ListNode *lp=new ListNode(l1->val);
                lr->next=lp;
                lr=lr->next;
                l1=l1->next;
            }
        }
        return l3;
    }
};