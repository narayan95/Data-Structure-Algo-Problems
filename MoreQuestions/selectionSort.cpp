// smaller elements left mai jate rahege
// sabse pehle index 0 array element ko lege aur baki ke array element se compare karege... agar kisi se bhi vo bada hoga to array elements ko swap kr dege .. thus ab swap ke baad index 0 pr vo chota element aa gaya to bache hue elements se fir vo chota element hi compare hoga aur finally hame smallest element mil jayega left mai aur yahi same process ham baaar baar repeat karege
#include<bits/stdc++.h>
using namespace std;

void selection(int *arr,int size)
{
    if(size==1)// base condition is size ki agar element hi ek hai to sorted hoga na hamara array
    return ;
    for(int i=1;i<size;i++)
    {
        if(arr[0]>arr[i])
        swap(arr[0],arr[i]);
    }// is loop se sabse smallest element leftmost position pr aa jayega aur fir ham array ko increment krke next element pr point karege aur size by 1 decrease karege and fir us array ki smallest element ko us array ke leftmost position pr rakhege and same baki ke elements ke liye karege by recursion
    selection(arr+1,size-1);

}
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    selection(arr,size);
}