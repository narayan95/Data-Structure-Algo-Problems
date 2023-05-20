//used a pointer j which keeps information regarding the length of the modified array and modifying in the original array itself for const space solution
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int remove_duplicate(int arr[],int n){
       
       int j=0,i=0;
       while(i<n)
       {
          arr[j]=arr[i];
           int elem=arr[j];
          j++;
          while(arr[i]==elem&&i<n)
            i++;
          
          
       }
       return j;
    }
};