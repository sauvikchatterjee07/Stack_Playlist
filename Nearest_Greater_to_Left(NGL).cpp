  
  
  vector<int> nextLargerElement(vector<int> arr, int n){
    vector<int> v; // creating a vector for storing result 
    stack <int> s; // creating a stack for temp. hold the values from array
    s.push(arr[0]);
    v.push_back(-1);
    
    
    for (int i=1;i<n;i++){ 
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
