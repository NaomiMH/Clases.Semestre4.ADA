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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head!=NULL && head->next!=NULL){
            ListNode *P=head;
            ListNode *Q = head->next;
            ListNode *N;
            while(Q!=NULL){
                if(P->val==Q->val){
                    N=Q->next;
                    delete Q;
                    Q=N;
                    P->next=Q;
                }
                else{
                    P=Q;
                    Q=Q->next;
                }
            }
        }
        return head;
    }
};
