class Solution {
public:
    int diameter(TreeNode *root,int &ans)
    {
        if(!root)
        return 0;
        int lh=diameter(root->left,ans);
        int rh=diameter(root->right,ans);
        ans = max(ans,lh+rh);
        return 1 + max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        diameter(root,ans);
        return ans;
    }
};