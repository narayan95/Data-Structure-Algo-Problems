/*
Consider the problem:
You have a row of binary digits arranged randomly. Arrange them in such an 
order that all 0’s precede all 1’s or vice-versa. The only constraint in arranging them is that you are 
allowed to interchange the positions of binary digits if they are not similar. 
 Implement an algorithm for Bubble sort and Insertion sort for binary value as input like 
 1 1 0 1 0 1 0 0 0.
 Compute the Time Complexity and Display the output as 0 0 0 0 0 1 1 1 1.
 
 Algorithm:

 -> Bubble sort
    1) traverse from left and compare adjacent elements and the higher one is placed at right side
    2) in this way, the largest element is moved to the rightmost end at first
    3) the process is then continued until whole data is sorted

  -> Insertion sort
    1)Compare the current element to its predecessor. 
    If the key element is smaller than its predecessor, compare it to the elements before. 
    Move the greater elements one position up to make space for the swapped element.
 

 */

#include<bits/stdc++.h>
using namespace std;

void Bubble(vector<int>arr)
{
    for(int i=0;i<arr.size();i++)
    {
        bool flag=1;
        for(int j=0;j<arr.size()-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=0;
            }
        }
        if(flag)
        break;
    }
    cout<<"Array after bubble sorting"<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}   

void Insertion(vector<int>arr)
{
    for(int i=1;i<arr.size();i++)
    {
        int j=i;
        while(j>=1)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
                j--;
            }
            else
                break;
        }
    }
     cout<<"Array after Insertion sorting"<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int>arr={1,1,0,1,0,1,0,0,1};
    clock_t start,end;
    start=clock();
    Bubble(arr);
    end=clock();
    cout<<"Time taken to sort the array via bubble sort is "<< (end- (float)start) / CLOCKS_PER_SEC <<endl; 
    start=clock();
    Insertion(arr);
    end=clock();
    cout<<"Time taken to sort the array via bubble sort is "<< (end- (float)start) / CLOCKS_PER_SEC <<endl; 

}