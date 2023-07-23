class Solution {
public:
    void f(TreeNode* root,int &cnt,int &ans,int k)
    {
        if(!root)
            return ;
        f(root->left,cnt,ans,k);
        cnt++;
        if(cnt==k)
            ans=root->val;
        f(root->right,cnt,ans,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt=0,ans;
        f(root,cnt,ans,k);
        return ans;
    }
};