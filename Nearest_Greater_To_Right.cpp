


vector<int> nextLargerElement(vector<int> arr, int n){
    vector<int> v; // creating a vector for storing result 
    stack <int> s; // creating a stack for temp. hold the values from array
    s.push(arr[n-1]);
    v.push_back(-1); //Initializing with the last value of the array because no element is present after that element.
                     //And pushing -1 to the result for the same reason
  
  
    for (int i=n-2;i>=0;i--){ //Traverse the loop for the second last element of the array because the first case is solved in initialization
     
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
    reverse(v.begin(),v.end()); // while returning reverse the vector and return it.
    return v;
  }
     

// Time Complexity: O(N)
// Auxiliary Space: O(N)
