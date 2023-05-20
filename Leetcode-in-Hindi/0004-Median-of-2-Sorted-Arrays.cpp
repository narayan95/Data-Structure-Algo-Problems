//In this approach we are using two pointers concept only.

//in this question with 2 pointer approach our main focus is to get the middle  element when both arrays are merged and sorted. so hamne ek mid variable banaya aur vo hamari middle most element ki value ko store karegi. and for cases jab middle elements 2 ho tab prev variable role play karegi. 

//now likewise we do sorting of two sorted arrays jisme dono pointers vale element ko compare karege aur jo smaller hota tha vo merged array mai jata tha , same concept is used but rather than creating a new array , we simply used mid and prev variables to just focus on the middle element.

// through the while loop,  we area getting the value of middle elements of the two sorted arrays and thus later returning the median.

//inside the loop nothing but the logic of merging two sorted arrays is used and it runs till (length of merged array)/2 .
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,cnt=0;
        double mid=0,prev=0;
        //mid is 
        int n=nums1.size() ,m=nums2.size();
        int total= (m+n)/2;
        while(cnt<=total)
        {
            prev=mid;
            if(i<n&&j<m)
            {
                mid= min(nums1[i],nums2[j]);
                if(mid==nums1[i])
                i++;
                else
                j++;
            }
            else if(i<n)
            {
                mid=nums1[i];
                i++;
            }
            else if(j<m)
            {
                mid=nums2[j];
                j++;
            }
            cnt++;
        }
        if((m+n)%2==0)
        {
            return (prev+mid)/2.0;
        }
        else
        return mid;
    }
};