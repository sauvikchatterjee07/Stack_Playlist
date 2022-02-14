    
    
    TC - O(n)
    SC - O(n)
    
    
    
    int minAddToMakeValid(string s) {
        stack<char> st;
        
        for(auto i: s){
            if(i == '(')
                st.push(i);
            else{
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(i);
            }
        }
        return st.size();
    }
    
    
    TC - O(n)
    SC - O(1)
    
    int minAddToMakeValid(string s) {
    int open = 0, close = 0;
    
    for(char c : s){
        if(c == '(')
            open++;
        else if (open > 0 && c == ')')
            open--;
        else
            close++;
    }
    return open + close;
    }
