class Solution{
public:
    Node* build(int &i,int bound,int pre[],int size)
    {
        if(i==size || pre[i]>bound)
            return NULL;
        Node* root=newNode(pre[i++]);
        root->left=build(i,root->data,pre,size);
        root->right=build(i,bound,pre,size);
        return root;
    }

    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    {
        int i=0;
        return build(i,INT_MAX,pre,size);
    }
};