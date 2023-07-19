class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next))
            return head;
        ListNode* temp=head;
        while(temp->next)
        {
            if(temp->val==temp->next->val)
            {
                ListNode* del=temp->next;
                temp->next=del->next;
                delete del;
            }
            else
            temp=temp->next;
        }
        return head;
    }
};