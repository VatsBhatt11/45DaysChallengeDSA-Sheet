Node *mergeList(Node* l1,Node* l2)
{
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    if(l1->data > l2->data)
        swap(l1,l2);
    Node* ans=l1;
    while(l1 && l2)
    {
        Node* temp=NULL;
        while(l1 && l1->data <= l2->data)
        {
            temp=l1;
            l1=l1->bottom;
        }
        temp->bottom=l2;
        swap(l1,l2);
    }
    return ans;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    if(!root || !root->next)
        return root;
    root->next=flatten(root->next);
    return mergeList(root,root->next);
}