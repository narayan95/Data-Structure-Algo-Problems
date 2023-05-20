#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int numofsubset(int arr[], int n)
    {
        sort(arr,arr+n);
        int cnt=0;
        if(n==1)
            return 1;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]+1==arr[i+1])
                continue;
            cnt++;
        }
        cnt++;
        return cnt;
    }
};