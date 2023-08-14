/*
Design and Implement algorithm for searching techniques Linear Search and Binary Search. 
Compute the Time Complexity and Display.

Algorithm:
-> Linear Search
    1) Search all elements of array one by one until either the element is found or whole array is tranversed
->Binary Search
    1) Declare two integers and initialiize them with starting and ending position of the array
    2) find the mid position between those two integers and check whether element is found or not
    3) if the mid position element is greater than the target element then we reduce the search space by searching between the left half array
    4) if the middle element is smaller than the target element then we reduce the search space by searching only in the right half of the array
    5) repeat the steps until either element is found or the start integer becomes greater than the end position
*/

#include<bits/stdc++.h>
using namespace std;

void linear(vector<int>&arr, int k)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==k)
        {
            cout<<"Element found in the array\n";
            return;
        }
    }
    cout<<"Element was not found in the array\n";

}

void binary(vector<int>&arr, int k)
{
    int s=0,e=arr.size();
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]==k)
        {
            cout<<"Element found in the array\n";
            return;
        }
        else if(arr[mid]>k)
            e=mid-1;
        else
            s=mid+1;
    }
    cout<<"Element was not found in the array\n";
}


int main()
{
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    clock_t start,end;
    int k;
    cin>>k;
    start=clock();
    linear(arr,k);
    end=clock();
    cout<< "Time Taken for Linear Search= " <<(end - (float)start) /CLOCKS_PER_SEC <<" sec\n\n";
    start=clock();
    binary(arr,k);
    end=clock();
    cout<< "Time Taken for Binary Search= " <<(end - (float)start) /CLOCKS_PER_SEC <<" sec\n\n";
}




