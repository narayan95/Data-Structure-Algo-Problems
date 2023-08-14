/*
Design and Implement Quick sort algorithm to sort a given list of unsorted elements in ascending 
order and determine the time required to sort the elements. Repeat the experiment for different 
values of n, the number of elements in the 1st to be sorted and plot a graph of the time taken versus 
n. The elements can be read from the user or can be generated using the random number generator.*/

/* Algorithm
1) pick up a element and put it at its correct position
2) Now ensure all the elements to the left of that pivot element are less than the pivot element and elements at right side of the pivot element are greater than the pivot element
3) repeat same steps for left and right half of the pivot

*/
#include<bits/stdc++.h>
using namespace std;

int sort_the_pivot(vector<int>&arr,int s,int e)
{
    int pivot_elem = arr[s];
    int pivot=s-1;
    for(int i=s;i<=e;i++)
    {
        if(arr[i]<=pivot_elem)
            pivot++;
    }
    swap(arr[pivot], arr[s]);
    int i=s,j=e;
    while(i<pivot && j>pivot)
    {
        while(i<pivot && arr[i]<=pivot_elem)
        i++;
        while(j>pivot && arr[j]>pivot_elem)
        j--;
       { if(i<pivot&&j>pivot)
            swap(arr[i],arr[j]);
        i++;
        j--;}
    }
    
    return pivot;

}

void quick(vector<int>&arr, int s ,int e)
{
    if(s>=e)
    return;
    int pivot;
    pivot= sort_the_pivot(arr,s,e);
    quick(arr,s,pivot-1);
    quick(arr,pivot+1,e);
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
    quick(arr,s,e);
    end=clock();
    cout<<"Sorted Array after performing quick sort operation"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Time taken to sort the array via merge sort is "<< (double)(end-start) / CLOCKS_PER_SEC <<endl; 

 }