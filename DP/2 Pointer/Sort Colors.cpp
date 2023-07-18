class Solution {
public:
    void sortColors(vector<int>& v) {
        int n=v.size(),l=0,h=n-1,m=0;
        while(m<=h)
        {
            if(v[m]==0)
                swap(v[m++],v[l++]);
            else if(v[m]==1)
                m++;
            else
                swap(v[m],v[h--]);
        }
    }
};