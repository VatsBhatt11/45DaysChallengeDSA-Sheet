class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<vector<int>>q;
        for(auto it:points)
        {
            int x=it[0],y=it[1];
            q.push({(x*x + y*y),x,y});
            if(q.size()>k)
                q.pop();
        }
        for(int i=0;i<k;i++)
        {
            vector<int>top=q.top();
            q.pop();
            ans.push_back({top[1],top[2]});
        }
        return ans;
    }
};