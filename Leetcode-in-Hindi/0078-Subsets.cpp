// Concept of recursion is used here to form subsets

// concept of inclusion and exclusion is used to form subsets

//like for [1 ,2 ,3 ]
// firstly exclude 1 and include 2
// so 2 subsets-> [2,3] and [1,2,3]
//now in both exclude 2 and include 2
//so 4 subsets-> [3], [2,3] and [1,3], [1,2,3]
//now same for 3
// so 8 subsets -> [],[3] and [2],[2,3] and [1],[1,3] and [1,2], [1,2,3] answer..

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<int>& nums,vector<int>output,int index,vector<vector<int>>&ans)
    {
        if(index>=nums.size())
        {
            ans.push_back(output);
            return ;
        }
        solve(nums,output,index+1,ans);// this is responsible for excluding numbers by incrementing the index
        output.push_back(nums[index]);
        solve(nums,output,index+1,ans);// this is responsible for including numbers by adding it to output and then incrementing index
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        vector<int>output;
        vector<vector<int>> ans;
        solve(nums,output,index,ans);
        return ans;
    }
};