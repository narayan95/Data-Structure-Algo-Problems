#include<iostream>
using namespace std;
bool linearSearch(int *arr,int key,int size)
{
    if(size==0)
    return false;
    if(arr[0]==key)
    return true;
    return linearSearch(arr+1,key,size-1);
    //agar element arr[0] ke barabar nhi hua to ham recursion ka use krege aur arr index ko next keyent pr point krege jisse ki new function call mai arr[0] jo mera purane function call ka arr[1] tha uske saath check krege key ko , agar same hua to true nhi to same process repeat hoga until arr array ke bahar na point krne lage

}
int main(){
    int arr[]={3,5,4,2,6};
    int key=2,size=5;
    if(linearSearch(arr,key,size))
    cout<<"element found";
}