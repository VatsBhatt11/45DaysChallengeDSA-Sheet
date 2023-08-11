class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int it:nums)
            freq[it]++;
        int n=nums.size();
        vector<vector<int>>bucket(n+1);
        for(auto it:freq)
            bucket[it.second].push_back(it.first);
        vector<int>ans;
        for(int i=bucket.size()-1;i>=0 && ans.size()<k;i--)
        {
            for(int it:bucket[i])
            {
                //cout << it << " ";
                ans.push_back(it);
                if(ans.size()==k)
                    break;
            }
        }
        return ans;
    }
};