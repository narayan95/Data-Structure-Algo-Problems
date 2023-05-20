
//marking the visited indexes to its negative value to find the repeating and missing elements in the same array
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
          if(arr[abs(arr[i])-1]<0)
          {
              ans.push_back(abs(arr[i]));
          }
          else
          arr[abs(arr[i])-1]= -arr[abs(arr[i])-1];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                ans.push_back(i+1);
                return ans;
            }
        }
    }
};