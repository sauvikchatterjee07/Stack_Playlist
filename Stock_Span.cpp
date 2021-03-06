//Leetcode 901    


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


// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

  vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> v; // creating a vector for storing result 
    stack <long long> s; // creating a stack for temp. hold the values from array
    for (int i=0;i<n;i++){ 
      if(s.size() ==0) // when stack size is empty there is no element in stack return output as -1;
        v.push_back(-1);
      else if (s.size()>0 && s.top()>arr[i]) // when there is element in stack and stack top is greater then array element 
      {
        v.push_back(s.top()); // take stack top in the result vector 
      }
      else if (s.size()>0 && s.top()<=arr[i]) // when there is element in stack and that element is less then array element 
      {
        while(s.size()>0 && s.top()<=arr[i]) // upto when there is element and stack top is less then array's element delete the element from stack
        {
          s.pop(); // delete the element from stack
        }
        if (s.size()==0) // when stack became empty return -1
        {
          v.push_back(-1);
        }
        else
        {
          v.push_back(s.top()); // else push stack top in the vector 
        }
      }
      s.push(arr[i]); // push array in stack
    }
    return v;
  }
