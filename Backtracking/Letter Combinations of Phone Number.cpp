class Solution {
public:
    void f(int i,string s,string digits,map<char,string>m,vector<string>&ans)
    {
        if(s.size()==digits.size())
        {
            ans.push_back(s);
            return ;
        }
        for(auto it:m[digits[i]])
            f(i+1,s+it,digits,m,ans);
    }

    vector<string> letterCombinations(string digits) {
        map<char,string>m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        vector<string>ans;
        if(digits.size())
            f(0,"",digits,m,ans);
        return ans;
    }
};