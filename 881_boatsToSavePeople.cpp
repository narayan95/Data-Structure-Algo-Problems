// Approach
// We used the concept of double pointer and sorting here.
// sabse pehle array ko sort kr diya aur fir ek pointer ko 1st element pr rakha aur dusre ko last element pr. fir hamne loop chalaya ki jab tak mera first pointer (i) mere second pointer (j) se chota ya barabar hai loop ko chalne dena.
// fir hamne dekha ki agar first element aur last element ka sum limit se kam ya barabar hai to matleb ek boat pr dono aa jayege thus count++ aur fir i and j ko next element pr point krwaya. vahi agr aisa na ho to mtlb ek boat pr sirf mota vala aadmi aayega isliye count badakar usse halke vale aadmi pr jakar fir sum of halka + bhari ko check krte rahege . agr aisa case bane ki i aur j same element pr point krne lage to fir ham sidhe vo aadmi ek boat pr akele sawar hoga aur ye case hamesha ending case hi ho skta thus ham loop se bahar aa gaye.

// Complexity
// Time complexity:
// O(NlogN)

// Code
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0,count=0,j=people.size()-1;
        sort(people.begin(),people.end());
        while(i<=j)
        {
            if(i==j)
            {
                count++;
                break;
            }

            else if(people[i]+people[j]<=limit)
            {
                count++;
                i++;
                j--;
            }
            else
            {
                count++;
                j--;
            }
        }
        return count;
    }
};