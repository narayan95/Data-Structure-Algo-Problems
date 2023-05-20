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
int calculate(int n)
{
    
    return 3+calculate(n-2);
}
void solution()
{
int a;
cin>>a;
int n=a;
if(a==1||a==2)
    cout<< 0<<endl;
else if(a==3)
    cout<< 2<<endl;
else if(a==4)
    cout<< 3<<endl;
else if(n%2==0)
{
    n=n-6;
    n=n/2;
    cout<<a+n<<endl;
}
else
{
    n=n-5;
    n/=2;
    cout<<a+n<<endl;
}


//cout<<calculate(n)<<endl;

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