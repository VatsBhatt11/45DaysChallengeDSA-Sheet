class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            TreeNode* temp=p.first;
            int x=p.second.first,y=p.second.second;
            m[x][y].insert(temp->val);
            if(temp->left)
                q.push({temp->left,{x-1,y+1}});
            if(temp->right)
                q.push({temp->right,{x+1,y+1}});
        }
        for(auto it:m)
        {
            vector<int>v;
            for(auto itr:it.second)
                v.insert(v.end(),itr.second.begin(),itr.second.end());
            ans.push_back(v);
        }
        return ans;
    }
};