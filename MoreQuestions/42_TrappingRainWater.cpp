
//Before coming to this, solve Q11_Container with most water as concept same hi hai dono ka

// Hamne 2 pointer approach ka use kiya hai. first pointer at the starting and 2nd pointer at the end of array height.

// dono pointer jis height pr point kr rhe hai unme se pehle ham choti vali height nikalege kyunki pani chote vale ke hisab se hi hamesa fill hogi.

// fir ab hame us choti vali height se badi height ko search krna hai by incrementing/decrementing the pointer because tabtak pani store hoti rahegi aur kitni hogi ?? -> jitni choti vali ki height thi minus choti vali height se badi height milne tak beech mai jo towers ki height hai , kyunki jitna towers ki height hai utne part mai pani store nhi ho payega. 

//example: heights of towers = {h,h/2,h} ->  height h se lekar height h ke beech mai yadi koi h/2 height ka tower nhi hota to total h height tak pani store hota but ab h/2 hi hoga 

// terminating condition jab starting pointer ending pointer se equal ya badi ho jaye 


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int water=0,s=0,e=height.size()-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            int mini=min(height[s],height[e]);
            while(height[s]<=mini&&s<e)
            {
                water+=mini-height[s];
                s++;
            }
            while(height[e]<=mini&&s<e)
            {
                water+=mini-height[e];
                e--;
            }
        }
        return water;
    }
};