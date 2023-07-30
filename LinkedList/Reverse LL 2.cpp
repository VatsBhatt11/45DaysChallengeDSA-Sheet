class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*dummy=new ListNode(0,head),*lprev=dummy,*cur=head;
        for(int i=0;i<left-1;i++)
        {
            lprev=cur;
            cur=cur->next;
        }
        ListNode* prev=NULL;
        for(int i=0;i<right-left+1;i++)
        {
            ListNode* temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        lprev->next->next=cur;
        lprev->next=prev;
        return dummy->next;
    }
};