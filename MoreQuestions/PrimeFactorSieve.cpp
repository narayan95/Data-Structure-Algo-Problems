//given n , we have to find the numbers who have min prime factors =n
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9+7

int main()
{
    int n,cnt=0;
    cin>>n;
    vector<int>arr(1e6,1);
    arr[0]=0;
    for(int i=2;i<=1e6;i++)
    {
        for(int j=i;j<=1e6;j=j+i)
        {
            arr[j]++;
        }
    }
    for(int i=1;i<=1e6;i++)
    {
        if(arr[i]>=n)
        cnt++;
    }
    cout<<cnt;
}