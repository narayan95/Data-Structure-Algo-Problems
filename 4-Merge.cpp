
/*
Design and Implement a Merge Sort algorithm to sort a given set of elements and determine the 
time required to sort the elements. Repeat the experiment for different values of n, the number of 
elements in the list to be sorted. The elements can be read from the user or can be generated using 
the random number generator.

-> Algorithm:
    mergesort(arr,l,h):
    1) Find the middle point to divide the array into two halves: m = ( l + h ) / 2
    2) call mergesort for the first half: mergesort(arr , l , m )
    3) call mergesort for the second half: mergesort(arr ,m+1 , h )
    4) continue till low is less than high
    5) merge the two halves : merge(arr,l,m,h)

    merge(arr,l,m,h):
    1) Declare two arrays
    2) Fill the first array element from s to mid and second array element from mid+1 to e
    3) compare elements of first and second array and modify the main array accordingly.

*/
 #include<bits/stdc++.h>
 using namespace std;
void display_arr(vector<int>arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

void mergesort(vector<int>&arr,int s,int e,int mid)
{
    int size1= mid-s+1;
    int size2= e-mid;
    int *arr1,*arr2;
    arr1= new int[size1];
    arr2= new int[size2];
    int k=s;
    for(int i=0;i<size1;i++)
    {
        arr1[i] = arr[k++];
    }
    for(int i=0;i<size2;i++)
    {
        arr2[i]= arr[k++];
    }
    int i=0,j=0;
    k=s;
    while(i<size1&&j<size2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k++]=arr1[i];
            i++;
        }
        else
        {
            arr[k++]=arr2[j++];
        }
    }
    while(i<size1)
    {
        arr[k++]=arr1[i++];
    }
    while(j<size2)
    {
        arr[k++]=arr2[j++];
    }
}
    void merge(vector<int>&arr,int s,int e)
    {
        if(s>=e)
        return;
        int mid= s+(e-s)/2;
        merge(arr,s,mid);
        merge(arr,mid+1,e);
        mergesort(arr,s,e,mid);
    }


 int main()
 {
    vector<int>arr;
    for(int i=0;i<rand();i++)
        arr.push_back(rand());// using rand() function, we put here random numbers in array
    int n = arr.size();
    int s = 0, e = n-1;
    clock_t start,end;
    start=clock();
    merge(arr,s,e);
    end=clock();
    cout<<"Sorted Array after performing merge sort operation"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Time taken to sort the array via merge sort is "<< (double)(end-start) / CLOCKS_PER_SEC <<endl; 

 }