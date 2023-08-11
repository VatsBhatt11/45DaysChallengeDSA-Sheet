class StockSpanner {
public:
    stack<pair<int,int>>st;
    int ind;
    StockSpanner() {
        ind=-1;
    }
    
    int next(int price) {
        ind++;
        while(!st.empty() && st.top().second<=price)
            st.pop();
        if(st.empty())
        {
            st.push({ind,price});
            return ind+1;
        }
        int ans=ind-st.top().first;
        st.push({ind,price});
        return ans;
    }
};