class Solution {
public:
    ListNode* reverse(ListNode* root)
    {
        if(!root || !root->next)
            return root;
        ListNode* prev=NULL,*next=prev;
        while(root)
        {
            next=root->next;
            root->next=prev;
            prev=root;
            root=next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head  || !head->next)
            return true;
        ListNode* slow=head,*fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        while(slow)
        {
            if(slow->val!=head->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
};