    //here we are checking is the array sorted or not using recursion
#include<iostream>
using namespace std;
bool issorted(int arr[],int size)
{
    //base condition sabse pehle check krte hai
    //hame pata hai ki agar arrar mai sirf 0 ya 1 element hoga to bagal ke element se compare krna possible hi nhi hoga
    //isiliye ye base ham banayege
    if(size==1||size==0)
        return true;

//  now comparing the first and 2nd element 
    if(arr[0]>arr[1]) //simply agr left vala bada hai to false return kr do
        return false;
    // now ab recursion call krege to {1,2,3,4,5} mai 1 aur 2 ka comparison hogya thus compare krege 2 aur 3 ko
    //isliye ab ham next vale index pr jayege array mai aur size ko bhi kam karege kyunki new arry is now {2,3,4,5}
    return issorted(arr+1,size-1); 
    
}
int main()
{
    int arr[]={1,2,3,4,5};
    int size=5;
    if(issorted(arr,size))
        cout<<"the array is sorted\n";
    else
        cout<<"unsorted array\n";

}