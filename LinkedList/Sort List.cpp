class Solution {
public:
    ListNode* mergeList(ListNode* l1,ListNode* l2)
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val > l2->val)
            swap(l1,l2);
        ListNode* ans=l1;
        while(l1 && l2)
        {
            ListNode* temp=NULL;
            while(l1 && l1->val <= l2->val)
            {
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            swap(l1,l2);
        }
        return ans;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode*temp=NULL,*slow=head,*fast=slow;
        while(fast && fast->next)
        {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        return mergeList(l1,l2);
    }
};