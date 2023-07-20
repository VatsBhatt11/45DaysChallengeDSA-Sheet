class Solution {
public:
    TreeNode* construct(vector<int>&nums,int l,int r)
    {
        if(l>r)
            return NULL;
        int m=l+(r-l)/2;
        TreeNode* ans=new TreeNode(nums[m]);
        ans->left=construct(nums,l,m-1);
        ans->right=construct(nums,m+1,r);
        return ans;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size())
            return NULL;
        TreeNode* ans = construct(nums,0,nums.size()-1);
        return ans;
    }
};