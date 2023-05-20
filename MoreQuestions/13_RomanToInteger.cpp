
// # Intuition
// problem sirf us case mai hai jab i just pehle aa raha other character ke. FOR example:

//  'IV' and 'VI'  mai agar directky 5+1 krde to both will give 5+1=6 but we know that IV=4 . thus ab back to front move krne vale hai 

// # Approach
// Ham piche se 2 characters i, i+1 ki value compare krte hue 0th index ki taraf move kr rahe hai. agar i+1th character ki value ith character se badi hai yani "iv" vali case to ham ans mai "v" ki value - "i" ki value (5-1=4) ko push kr rahe and for the case of "vi" i+1th character is < ith character thus yaha ham "v" ki value + "i" ki value (5+1=6) ko push kr rahe

// NOTE: starting mai ans = string ke last character ki value because ham ith element ki value ko deal kr rahe hai i+1th ko nhi aur last element ki value uske i+1th element se nhi ki ja skti  

// # Complexity
// - Time complexity:O(N)

// - Space complexity:O(1)

// # Code
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int value(char c)
    {
        switch(c)
        {
            case 'I':return 1;break;
            case 'V':return 5;break;
            case 'X':return 10;break;
            case 'L':return 50;break;
            case 'C':return 100;break;
            case 'D':return 500;break;
            case 'M':return 1000;break;
        }
        return 0;
    }
    int romanToInt(string s) {
        
        int ans=value(s[s.length()-1]);
        for(int i=s.length()-2;i>=0;i--)
        {
            int sum=value(s[i]);
            if(value(s[i])>=value(s[i+1]))
                ans+=sum;
            else
                ans-=sum;
        }
        return ans;


    }
};
