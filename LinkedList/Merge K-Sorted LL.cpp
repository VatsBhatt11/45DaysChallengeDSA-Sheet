class cmp{
    public:
    bool operator()(ListNode* a,ListNode* b)
    {
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode();
        ListNode* tail=dummy;
        priority_queue<ListNode*,vector<ListNode*>,cmp>q;
        for(auto it:lists)
            if(it)
                q.push(it);
        while(!q.empty())
        {
            ListNode* temp=q.top();
            q.pop();
            tail->next=temp;
            tail=temp;
            if(temp->next)
                q.push(temp->next);
        }
        return dummy->next;
    }
};