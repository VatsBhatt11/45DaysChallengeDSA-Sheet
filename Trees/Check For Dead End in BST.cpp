bool f(Node* root,int l,int r)
{
    if(!root)
        return false;
    if(!root->left && !root->right)
        return (l==r);
    return (f(root->left,l,root->data-1) || f(root->right,root->data+1,r));
}

bool isDeadEnd(Node *root)
{
    return f(root,1,INT_MAX);
}