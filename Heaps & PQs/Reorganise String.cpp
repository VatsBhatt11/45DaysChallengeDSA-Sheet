class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>q;
        unordered_map<char,int>m;
        for(auto it:s)
            m[it]++;
        for(auto it:m)
            q.push({it.second,it.first});
        string ans="";
        while(q.size()>1)
        {
            auto a=q.top();
            q.pop();
            auto b=q.top();
            q.pop();
            ans+=a.second;
            ans+=b.second;
            a.first--;
            b.first--;
            if(a.first)
                q.push(a);
            if(b.first)
                q.push(b);
        }
        if(!q.empty())
        {
            if(q.top().first>1)
                return "";
            else
                ans+=q.top().second;
        }
        return ans;
    }
};