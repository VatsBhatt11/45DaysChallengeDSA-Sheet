class Solution {
public:
    void f(TreeNode* root,string s,vector<string>&ans)
    {
        s+=to_string(root->val);
        if(!root->left && !root->right)
        {
            ans.push_back(s);
            return ;
        }
        s+="->";
        if(root->left)
        f(root->left,s,ans);
        if(root->right)
        f(root->right,s,ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root)
            f(root,"",ans);
        return ans;
    }
};