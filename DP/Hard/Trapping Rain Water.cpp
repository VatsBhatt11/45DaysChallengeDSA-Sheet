class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,n=height.size();
        int l=0,r=n-1,lmx=0,rmx=0;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                if(height[l]>=lmx)
                    lmx=height[l];
                else
                    ans+=(lmx-height[l]);
                l++;
            }
            else
            {
                if(height[r]>=rmx)
                    rmx=height[r];
                else
                    ans+=(rmx-height[r]);
                r--;
            }
        }
        return ans;
    }
};