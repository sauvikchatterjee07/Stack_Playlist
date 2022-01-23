    stack<pair<int,int>>st; 
    int count = 0;  // this acts as the index or we can say keep the track of the index of the element since we donot have the array of prices here 
    
    StockSpanner() {
        
    }
    
    int next(int price) {
         
        while(!st.empty() && st.top().first<=price)
        {
            st.pop();
        }
     
        int ans = (st.empty())?count+1:count-st.top().second;
        st.push({price,count}); // push into the stack the price with its count we can say we are pushing the {price,index of the element (i.e count)}
        count = count+1;
       
        
        return ans;
    }
