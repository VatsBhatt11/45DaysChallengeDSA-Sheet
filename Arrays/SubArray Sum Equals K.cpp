class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,prefix=0,n=nums.size();
        unordered_map<int,int>m;
        m[0]=1;
        for(int i=0;i<n;i++)
        {
            prefix+=nums[i];
            int left=prefix-k;
            ans+=m[left];
            m[prefix]++;
        }
        return ans;
    }
};