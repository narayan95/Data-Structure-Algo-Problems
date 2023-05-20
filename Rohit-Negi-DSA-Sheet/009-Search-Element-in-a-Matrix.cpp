#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size(),col=matrix[0].size();
        int s=0;
        int e=row*col-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int rowindex= mid/col;
            int colindex= mid%col;
            int element= matrix[rowindex][colindex];
            if(element==target)
            return true;
            else if(element>target)
            e=mid-1;
            else
            s=mid+1;
        }
        return false;
    }
};