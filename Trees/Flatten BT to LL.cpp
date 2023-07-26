class Solution {
public:
    /* Approach-1
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }*/
    
    /*Approach-2
    void flatten(TreeNode* root)
    {
        if(!root)
            return;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp=s.top();
            s.pop();
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
            if(!s.empty())
                temp->right=s.top();
            temp->left=NULL;
        }
    }*/

    /*Approach-3
    void flatten(TreeNode* root)
    {
        TreeNode* cur=root;
        while(cur)
        {
            if(cur->left)
            {
                TreeNode* prev=cur->left;
                while(prev->right)
                    prev=prev->right;
                prev->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;
        }
    }*/
};