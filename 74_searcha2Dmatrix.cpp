/*Logic:
    index/totalNoofColumns= row index and index%totalNoofColumns=column index.
    simply jo bhi index diya  hai usko agar total no of column se divide karege to row index niklega aur mod karege to col index niklega.
    bas yhi logic ka use krke binary search laga diya
*/
//Code
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0;
        int row=matrix.size();
        int col=matrix[0].size();
        int e=row*col-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int element=matrix[mid/col][mid%col];
            if(element==target)
                return 1;
            else if(element>target)
                e=mid-1;
            else
                s=mid+1;
        }
        return 0;
    }
};