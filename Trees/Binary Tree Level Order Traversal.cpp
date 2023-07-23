class Solution {
public:
    void f(TreeNode* root,unordered_map<TreeNode*,bool>m,vector<vector<int>>&ans)
    {
        if(!root)
            return;
        queue<TreeNode*>q;
        q.push(root);
        m[root]=true;
        while(!q.empty())
        {
            int s=q.size();
            vector<int>v;
            for(int i=0;i<s;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left && !m[temp->left])
                {
                    m[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right && !m[temp->right])
                {
                    m[temp->right]=true;
                    q.push(temp->right);
                }
            }
            ans.push_back(v);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        unordered_map<TreeNode*,bool>m;
        f(root,m,ans);
        return ans;
    }
};