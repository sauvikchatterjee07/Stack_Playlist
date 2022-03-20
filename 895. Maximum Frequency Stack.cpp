class FreqStack {
public:
    
    map<int, int> freq;
    map<int, stack<int>> elems_with_same_freq;
    int max_freq = 0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        //increase the frequency of the value
        freq[val]++;
        
        //push to the stack of the map where the group of elems are of same frequency
        elems_with_same_freq[freq[val]].push(val);
        
        //update the max freq
        max_freq = max(max_freq, freq[val]);
        
    }
    
    int pop() {
        
        //store the most freq ele && closest to the stack top ele in a variable
        int top_ele_with_most_freq = elems_with_same_freq[max_freq].top(); 
        
        //pop the element
        elems_with_same_freq[max_freq].pop();
        
        //decrease the count of the element in freq map
        freq[top_ele_with_most_freq]--;
        
        //come to the next stack if the stack{val} of max_freq{key} is empty
        if(elems_with_same_freq[max_freq].empty())
            max_freq--;
            
        return top_ele_with_most_freq;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
