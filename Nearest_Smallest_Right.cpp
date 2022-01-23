    

  vector<int> nsr(vector<int> heights){
    stack<pair<int, int>>s2;
    vector<int> right;
    s2.push({heights[n-1], n-1});
    right.push_back(n);
    int pseudo_index1_right = n; //Pseudo index is nothing but the exact next index of the last index of the vector.
                                 //This can be changed to -1 as per the question says

    for (int i=n-2; i>=0; i--)
    {
        while(s2.size()>0 && s2.top().first >= heights[i])
          s2.pop();

        if (s2.size()==0)
          right.push_back(pseudo_index1_right);
        else
          right.push_back(s2.top().second);

      s2.push({heights[i],i});
    }
    reverse(right.begin(),right.end());
  
    return right;
}
