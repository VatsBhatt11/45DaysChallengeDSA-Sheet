class Solution {
public:
    vector<int> findDuplicates(vector<int>&v) {
        vector<int>ans;
        for(int i=0;i<v.size();i++)
        {
            if(v[abs(v[i])-1]<0)
            ans.push_back(abs(v[i]));
            else
            v[abs(v[i])-1]=-1*v[abs(v[i])-1];
        }
        return ans;
    }
};