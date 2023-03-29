//bigger elements right mai jate rahege
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
void solution(int *arr,int size)
{
    if(size==1)
    return ;
    for(int i=0;i<size-1;i++)
    {
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }
    solution(arr,size-1);
}
int main()
{
  int arr[]={2,5,1,3,8};
  solution(arr,5);
  display(arr,5);
}


























