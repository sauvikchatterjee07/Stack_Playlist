class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int j = 0;
        for(int i: pushed){
            st.push(i);
            while(!st.empty() && popped[j] == st.top()){
                st.pop();
                j++;
            }
        }
        return j == popped.size();
    }
};
