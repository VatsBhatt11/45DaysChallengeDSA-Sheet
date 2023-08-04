class Solution {
public:
    Node* flatten_r(Node* head)
    {
        Node* cur=head,*tail=head;
        while(cur)
        {
            Node* child=cur->child;
            Node* next=cur->next;
            if(child)
            {
                Node* tail1=flatten_r(child);
                tail1->next=next;
                if(next)
                    next->prev=tail1;
                cur->next=child;
                child->prev=cur;
                cur->child=NULL;
                cur=tail;
            }
            else
                cur=next;
            if(cur)
                tail=cur;
        }
        return tail;
    }

    Node* flatten(Node* head) {
        if(head)
            flatten_r(head);
        return head;
    }
};