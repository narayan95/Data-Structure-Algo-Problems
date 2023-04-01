#include<bits/stdc++.h>
using namespace std;
bool binary(int arr[],int s,int e,int key)
{
    int mid=s+(e-s)/2;
    if(s>e)
    return false;
    if(arr[mid]==key)
    return true;
    else if(arr[mid]>key)
        e=mid-1;
    else
        s=mid+1;
    return binary(arr,s,e,key);

}
int main()
{
    int arr[]={1,2,3,4,5};
    int size=5,key=5;
    int s=0,e=size-1;
    bool ans=binary(arr,s,e,key);
    if(ans)
        cout<<"element found";
}