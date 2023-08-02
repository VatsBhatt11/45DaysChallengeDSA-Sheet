class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* front=head,*itr=head;
        while(itr)
        {
            front=itr->next;
            Node* copy=new Node(itr->val);
            itr->next=copy;
            copy->next=front;
            itr=front;
        }
        itr=head;
        while(itr)
        {
            if(itr->random)
                itr->next->random=itr->random->next;
            itr=itr->next->next;
        }
        itr=head;
        Node* dummy=new Node(0);
        Node* copy=dummy;
        while(itr)
        {
            front=itr->next->next;
            copy->next=itr->next;
            itr->next=front;
            copy=copy->next;
            itr=front;
        }
        return dummy->next;
    }
};