class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>m;
        for(auto it:nums)
            m[it]++;
        set<int>s(nums.begin(),nums.end());
        nums.clear();
        for(auto it:s)
        nums.push_back(it);
        int n=nums.size();
        int p1=0,p2=0;
        for(int i=0;i<n;i++)
        {
            int cur=nums[i]*m[nums[i]];
            int temp=p2;
            if(i>0 && nums[i]==nums[i-1]+1)
                p2=max(cur+p1,p2);
            else
                p2=cur+p2;
            p1=temp;        
        }
        return p2;
    }
};