
#include<bits/stdc++.h>
using namespace std;
/*
simply ham yaha two pointer concept aur recursion ka use kr rahe hai with base condition that left pointer should be less than the right pointer only.
now dono pointer vali heights ko lege ham and we will calculate the minimum of the height between them  and multipying it with width to calculate area and modifying area by taking maximum of present area and previous max area.
Fir ham chote pointer ko move karege bas because agar chota vala thoda bada ho jaye to aur pani ham store kr payege. also we could have written here:
*/

/*
while(height[i]<=minh&&i<j) i++;
while(height[j]<=minh&&i<j) j--;

*/

/*
this is because if the next element height is less than that of previous then no point of considering that element as its guarantee area will decrease.
so with this logic we are solving this in O(N) complexity.

Code
*/
class Solution {
public:
    int calc(int area,int i,int j,vector<int>& height)
    {
        if(i>=j)
            return area;
           int minh=min(height[i],height[j]);
            area=max(area,(minh*(j-i)));
            
            /*
            while(height[i]<=minh&&i<j) i++;
            while(height[j]<=minh&&i<j) j--;
            
            we can remove the below code with just above two lines too*/
            if(height[i]<height[j])
            {
                i++;
            }
            else if(height[j]<height[i])
            {
                j--;
            }
            else
            {
                i++;j--;
            }
       return calc(area,i,j,height);

    }
    int maxArea(vector<int>& height) {
        int area=0,i=0,j=height.size()-1;
        int ans=calc(area,i,j,height);
        return ans;
}

};
