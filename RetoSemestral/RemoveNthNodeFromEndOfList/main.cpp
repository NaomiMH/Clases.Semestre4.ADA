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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cant=0;
        ListNode* P=head;
        while(P!=NULL){
            cant++;
            P=P->next;
        }
        P=head;
        if(cant-n>0){
            int cont=1;
            while(cont!=cant-n){
                cont++;
                P=P->next;
            }
            ListNode* Q=P;
            P=P->next;
            Q->next=Q->next->next;
        }
        else{
            P=head;
            head=P->next;
        }
        delete P;
        return head;
    }
};
