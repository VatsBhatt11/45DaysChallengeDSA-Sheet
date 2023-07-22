class Solution {
public:
    void f(TreeNode* root,int &prev,int &ans)
    {
        if(!root)
            return ;
        f(root->left,prev,ans);
        if(prev!=-1)
            ans=min(ans,abs(root->val-prev));
        prev=root->val;
        f(root->right,prev,ans);
    }

    int getMinimumDifference(TreeNode* root) {
        int prev=-1,ans=INT_MAX;
        f(root,prev,ans);
        return ans;
    }
};