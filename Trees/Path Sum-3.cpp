class Solution {
public:
    int f(TreeNode* root,long long int targetSum)
    {
        if(!root)
            return 0;
        int cnt=0;
        if(root->val==targetSum)
            cnt++;
        cnt+=f(root->left,targetSum-root->val);
        cnt+=f(root->right,targetSum-root->val);
        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        return pathSum(root->left,targetSum) + f(root,targetSum) + pathSum(root->right,targetSum);
    }
};