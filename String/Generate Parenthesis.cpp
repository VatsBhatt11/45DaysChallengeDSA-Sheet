class Solution {
public:
    void f(int l,int r,int n,string s,vector<string>&ans)
    {
        if(l==r && l==n)
        {
            ans.push_back(s);
            return;
        }
        if(l<n)
        {
            s+="(";
            f(l+1,r,n,s,ans);
            s.pop_back();
        }
        if(r<l)
        {
            s+=")";
            f(l,r+1,n,s,ans);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        f(0,0,n,s,ans);
        return ans;
    }
};