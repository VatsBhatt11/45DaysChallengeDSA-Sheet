class Solution
{
    public: 
    void f(Node* root,Node* &prev,Node* &head)
    {
        if(!root)
            return ;
        f(root->left,prev,head);
        if(!prev)
            head=root;
        else
        {
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        f(root->right,prev,head);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        Node *prev=NULL,*head=NULL;
        f(root,prev,head);
        return head;
    }
};