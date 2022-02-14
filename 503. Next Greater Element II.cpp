    vector<int> nextGreaterElements(vector<int>& nums) {
    
        stack<int> st;
        int n = nums.size();
        
        for(int i = n-2; i>= 0; i--){
            while(!st.empty() && st.top()<=nums[i])
                st.pop();
            st.push(nums[i]);
        }
        vector<int> ans(n);
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && st.top()<=nums[i])
                st.pop();
            
            ans[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
    
        return ans;           
    }
