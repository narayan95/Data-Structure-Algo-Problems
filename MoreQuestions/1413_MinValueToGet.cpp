/*
APPROACH:

The concept of prefix sum is used in this problem. Hamne observe kiya ki prefix sum krne pr jaha bhi sum sabse chota aayega agr use positive banana hai to usse ek bade positive number se add krna hoga. is concept se ham loop chala rhe hai aur min value ko a mai store kara rahe hai.
Finally ham 1-a ko return kara de rahe hai aur kyunki hamne a ki value intitally 0 rakhi hai to agr pure array mai kabhi bhi elements ka sum negative nhi ho rha ho to 1-0 yani 1 return ho jayega thus edge cases bhi deal kr liye hamne
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minStartValue(vector<int>& nums) {
     int sum=0,a=0;
     for(int i=0;i<nums.size();i++)
     {
         sum+=nums[i];
         a=min(a,sum);
     }
        return -a+1;
    }
};