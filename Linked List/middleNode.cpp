class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*p1=head;
        int l=0;
        while(p1){
         l++;
            p1=p1->next;
        }
        ListNode*fast=head->next;
        ListNode*slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(l&1){ 
        return slow;}else{
            return slow->next;
        }
    }
};