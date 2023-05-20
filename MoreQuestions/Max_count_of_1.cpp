#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9+7
void display(int *arr,int n)
{
for(int i=0;i<n;i++)
   cout<<arr[i]<<" " ;
   cout<<endl;
}
void getarray(int *arr,int n)
{
for(int i=0;i<n;i++)
   cin>>arr[i] ;
}
void solution()
{
int n;
cin>>n;
string s;
cin>>s;
int arr1[n],arr2[n];
arr1[0]=0;
arr2[0]=1;
int count1=0,count2=1;
for(int i=1;i<n;i++)
{
    arr1[i]=((arr1[i-1])^(s[i-1]-48));
    arr2[i]=((arr2[i-1])^(s[i-1]-48));
    if(arr1[i]==1)
    count1++;
    if(arr2[i]==1)
    count2++;
}
if(count1>count2)
cout<<count1<<endl;
else
cout<<count2<<endl;
}
int main()
{
  int t;
cin>>t;
while(t--)
{
  solution();
}
}