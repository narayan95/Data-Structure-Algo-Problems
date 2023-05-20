#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	/* Function to replace every element with the
	next greatest element */
	void nextGreatest(int arr[], int n) {
	    // code here
	    int temp=arr[n-1];
	    arr[n-1]=-1;
	    for(int i=n-2;i>=0;i--)
	    {
	        int maxi= max(temp,arr[i+1]);
	        temp=arr[i];
	        arr[i]=maxi;
	    }
	}


};