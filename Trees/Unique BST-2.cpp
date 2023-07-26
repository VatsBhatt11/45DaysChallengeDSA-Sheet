class Solution {
public:
    vector<TreeNode*>f(int start,int end)
    {
        vector<TreeNode*>ans;
        if(start>end)
        {
            ans.push_back(NULL);
            return ans;
        }
        if(start==end)
        {
            ans.push_back(new TreeNode(start));
            return ans;
        }
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*>lft=f(start,i-1);
            vector<TreeNode*>rgt=f(i+1,end);
            for(auto lf:lft)
            {
                for(auto rg:rgt)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=lf;
                    root->right=rg;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return f(1,n);
    }
};