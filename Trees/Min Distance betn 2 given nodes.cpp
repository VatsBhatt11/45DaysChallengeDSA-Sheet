class Solution{
    public:
    Node* LCA(Node* root,int a,int b)
    {
        if(!root || root->data==a || root->data==b)
            return root;
        Node* lf=LCA(root->left,a,b);
        Node* rf=LCA(root->right,a,b);
        if(!lf && !rf)
            return NULL;
        if(!lf)
            return rf;
        if(!rf)
            return lf;
        return root;
    }
    
    int Dist2(Node* &root,int a,int dist)
    {
        if(!root)
            return -1;
        if(root->data==a)
            return dist;
        int l=Dist2(root->left,a,dist+1);
        if(l!=-1)
            return l;
        return Dist2(root->right,a,dist+1);
    }
        
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        Node* lca=LCA(root,a,b);
        int d1=Dist2(lca,a,0);
        int d2=Dist2(lca,b,0);
        return d1+d2;
    }
};