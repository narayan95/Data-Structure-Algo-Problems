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
int pivotIndex(int *arr,int s,int e)
{

    int elem=arr[s],count=0;
    display(arr,5);
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=elem)
        count++;
    }
    int p=s+count;
        swap(arr[s],arr[p]);// ab first element apni correct index pr aa chuka hai
        
    display(arr,5);
    int i=s,j=p+1;
    // is while loop se hamne jo elem ko uski sahi poistion pr fit kiya hai , uske left mai sirf usse chote elements ko rehne de rahe aur right mai sirf usse bade elements
    while(i<p&&j<=e)
    {
        while(arr[i]<=arr[p])
            i++;
        while(arr[j]>arr[p])
            j++;
        if(i<p && j<=e)
            swap(arr[i++],arr[j++]);
    }
    return p;


}
void quicksort(int* arr,int s,int e)
{
    if(s>=e)
    return;
    // pivot sort mai ham first element ko uske correct index pr place karege by running through loop and finding out that how many integers in array are less than the first element. p yaha vo index batayegi hame
    int p=pivotIndex(arr,s,e);
    // upar ke function se hame ek index ke left mai sare usse chote elements mil gye hai aur uske right mai usse bade
    // isliye jab us index ke baye aur daye elements ke saath ham same process karege using recursion to O(nlogn) time complexity mai hame sorted array mil jayega.
   quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);

}
int main()
{
  int arr[]={4,3,6,2,1};
  int size=5;
  int s=0,e=size-1;
  quicksort(arr,s,e);
  display(arr,5);
}