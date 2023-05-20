//prime num till int_max

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=6-1;
    vector<bool>prime(n,1);
    prime[0]=prime[1]=0;
    for(int i=2;i<n;i++)
    {
        if(prime[i])
        {
            for(int j=2*i;j<n;j=j+i)
            prime[j]=0;
        }
        
    }
    for(int i=0;i<=n;i++)
    {
        if(prime[i])
        cout<<i<<" ";
    }
}