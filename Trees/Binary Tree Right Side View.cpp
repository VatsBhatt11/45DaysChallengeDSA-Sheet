class Solution {
public:
    void f(TreeNode* root,int level,vector<int>&ans)
    {
        if(!root)
            return;
        if(ans.size()==level)
            ans.push_back(root->val);
        f(root->right,level+1,ans);
        f(root->left,level+1,ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        f(root,0,ans);
        return ans;
    }
};