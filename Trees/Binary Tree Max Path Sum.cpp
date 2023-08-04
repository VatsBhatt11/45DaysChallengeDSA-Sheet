class Solution {
public:
    int helper(TreeNode* root,int &ans)
    {
        if(!root)
            return 0;
        int ls=max(0,helper(root->left,ans));
        int rs=max(0,helper(root->right,ans));
        ans=max(ans,ls+rs+root->val);
        return max(ls,rs)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        helper(root,ans);
        return ans;
    }
};