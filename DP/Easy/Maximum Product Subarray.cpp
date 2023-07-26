class Solution {
public:
    int maxProduct(vector<int>& v) {
        int prefix=1,suffix=1,n=v.size(),ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(prefix==0)
                prefix=1;
            if(suffix==0)
                suffix=1;
            prefix=prefix*v[i];
            suffix=suffix*v[n-i-1];
            ans=max(ans,max(prefix,suffix));
        }
        return ans;
    }
};