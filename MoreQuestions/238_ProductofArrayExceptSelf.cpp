
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(size(nums),1);
        for(int i=1;i<size(nums);i++)
        {
            ans[i]=ans[i-1]*nums[i-1];
        }
        int suffixproduct=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i]*=suffixproduct;
            suffixproduct*=nums[i];
        }
        return ans;
    }
};