#include<bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int>heights){
  
    int n = heights.size();
    vector<int> left,right;
    stack<pair<int,int>> s1,s2;
    int pseudo_index_left =-1;
    int pseudo_index1_right =n;

    //NSL

      s1.push({heights[0], 0});
      left.push_back(-1);

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

    //NSR
      
    s2.push({heights[n-1], n-1});
    right.push_back(n);

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
    
    int m=INT_MIN;

    for (int i=0;i<n;i++)
    {   
        // taking max after finding area
        m=max(m,(right[i]-left[i]-1)*heights[i]);
    }
    return m;
  }

int main()
{   
    vector<int> v{2,1,5,6,2,3};
    cout<<getMaxArea(v);


    return 0;
}
