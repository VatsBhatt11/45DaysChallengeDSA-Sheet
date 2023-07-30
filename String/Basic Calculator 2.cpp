class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int n=s.size(),cur=0;
        char sign='+';
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
                cur=(cur*10)+(s[i]-'0');
            if(!isdigit(s[i]) && s[i]!=' ' || i==n-1)
            {
                if(sign=='+')
                    st.push(cur);
                if(sign=='-')
                    st.push(-1*cur);
                if(sign=='*')
                {
                    int x=st.top();
                    st.pop();
                    st.push(x*cur);
                }
                if(sign=='/')
                {
                    int x=st.top();
                    st.pop();
                    st.push(x/cur);
                }
                sign=s[i];
                cur=0;
            }
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};