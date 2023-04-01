#include<iostream>
using namespace std;
int sum(int arr[],int size)
{
    if(size==0)
    return 0;
    else if(size==1)//base condition size hai hamara 
    return arr[0];
    // yaha pr we are adding the current element aur bai ke elements ko add krne ke liye recursion ka use kr rahe hai
    return arr[0]+sum(arr+1,size-1);
    //arr+1 se ham array pointer ko next element ki taraf move kr rhe hai
}
int main()
{
    int arr[]={1,2,3,4,5};
    int sumu=sum(arr,5);
    cout<<sumu;
}