//https://www.codechef.com/START85C/problems/EPANLNK

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
string s;
cin>>s;
int ch1=s[s.size()-1]-'0';
int ch2=s[s.size()-2]-'0';
ch2=ch2%2;
cout<<ch2*10+ch1<<endl;

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