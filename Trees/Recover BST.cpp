class Solution {
public:
    void f(TreeNode* root,TreeNode* &first,TreeNode* &m,TreeNode* &last,TreeNode* &prev)
    {
        if(!root)
            return;
        f(root->left,first,m,last,prev);
        if(root->val<prev->val)
        {
            if(!first)
            {
                first=prev;
                m=root;
            }
            else
            last=root;
        }
        prev=root;
        f(root->right,first,m,last,prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* first=NULL,*m=NULL,*last=NULL;
        TreeNode* prev=new TreeNode(INT_MIN);
        f(root,first,m,last,prev);
        if(last)
        swap(first->val,last->val);
        else
        swap(first->val,m->val);
    }
};