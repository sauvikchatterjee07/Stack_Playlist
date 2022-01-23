//NEAREST SMALLEST ELEMENT INDEXES:

  vector<int> nsl(vector<int> heights){
      vector<int>left;
      stack<pair<int, int>> s1;
      s1.push({heights[0], 0});
      left.push_back(-1);
      int pseudo_index1_left = -1;

    for (int i=1;i<n;i++)
    {
        while(s1.size()>0 && s1.top().first>=heights[i])
            s1.pop();

        if (s1.size()==0)
          left.push_back(pseudo_index_left);
        else
          left.push_back(s1.top().second);
      s1.push({heights[i],i});
    }
    
    return left;
    
  }
