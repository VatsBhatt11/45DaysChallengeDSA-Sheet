class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>count(k);
        int sum=0;
        for(auto it:nums)
        {
            sum+=it;
            count[(sum%k + k)%k]++;
        }
        int ans=count[0];
        for(auto it:count)
        ans+=(it*(it-1))/2;
        return ans;
    }
};