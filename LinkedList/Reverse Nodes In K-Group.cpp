class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)
            return head;
        int cnt=0;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* prev=dummy,*cur=prev,*nex=cur;
        while(cur->next)
        {
            cur=cur->next;
            cnt++;
        }
        while(cnt>=k)
        {
            cur=prev->next;
            nex=cur->next;
            for(int i=1;i<k;i++)
            {
                cur->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=cur->next;
            }
            prev=cur;
            cnt-=k;
        }
        return dummy->next;
    }
};