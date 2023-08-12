class Solution {
public:
    bool isPalindrome(int l,int h,string s)
    {
        while(l<h)
        {
            if(s[l++]!=s[h--])
                return false;
        }
        return true;
    }

    void helper(int ind,string s,vector<string>&v,
    vector<vector<string>>&ans)
    {
        if(ind==s.size())
        {
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(isPalindrome(ind,i,s))
            {
                v.push_back(s.substr(ind,i-ind+1));
                helper(i+1,s,v,ans);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        helper(0,s,v,ans);
        return ans;
    }
};