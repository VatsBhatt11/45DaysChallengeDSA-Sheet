class Solution {
public:
    void f(TreeNode* root,int &ans)
    {
        if(!root)
            return ;
        if(root->left && !root->left->left && !root->left->right)
            ans+=root->left->val;
        f(root->left,ans);
        f(root->right,ans);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        f(root,ans);
        return ans;
    }
};