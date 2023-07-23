class Solution {
public:
    bool f(TreeNode* root,long mn,long mx)
    {
        if(!root)
            return true;
        if(root->val<=mn || root->val>=mx)
            return false;
        return f(root->left,mn,root->val)&&f(root->right,root->val,mx);
    }

    bool isValidBST(TreeNode* root) {
        long mn=LONG_MIN,mx=LONG_MAX;
        return f(root,mn,mx);
    }
};