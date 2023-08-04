class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=slow->next;
        slow->next=NULL;
        ListNode* nex=NULL,*prev=NULL;
        while(second)
        {
            nex=second->next;
            second->next=prev;
            prev=second;
            second=nex;
        }
        ListNode* first=head;
        second=prev;
        while(second)
        {
            ListNode* temp1=first->next,*temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1,second=temp2;
        }
    }
};