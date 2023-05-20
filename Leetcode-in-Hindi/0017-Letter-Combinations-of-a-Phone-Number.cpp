

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void formsubsets(string digits,int index,string output,vector<string>&ans,string digit[])
{
   if(index>=digits.length())
   {
       ans.push_back(output);
       return;
   }
   string temp= digit[digits[index]-'0'];
   for(int i=0;i<temp.length();i++)
   {
       output.push_back(temp[i]);
       formsubsets(digits,index+1,output,ans,digit);
       output.pop_back();
   }

}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()<=0)
        return ans;
        string output;
        string digit[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        formsubsets(digits,0,output,ans,digit);
        return ans;
    }
};