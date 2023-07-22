class Solution
{
    void predecessor(Node* root,Node* &pre,int key)
    {
        if(!root)
            return ;
        if(root->key < key)
        {
            pre=root;
            predecessor(root->right,pre,key);
        }
        else
            predecessor(root->left,pre,key);
    }
    
    void successor(Node* root,Node* &suc,int key)
    {
        if(!root)
            return ;
        if(root->key > key)
        {
            suc=root;
            successor(root->left,suc,key);
        }
        else
            successor(root->right,suc,key);
    }
    
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        predecessor(root,pre,key);
        successor(root,suc,key);
    }
};