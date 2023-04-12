#include<bits/stdc++.h>
using namespace std;
// condition for valid strings ye hai ki usme '//' ya '.' vagerah nhi rhna chahiye aur agar '..' kabhi encounter hota hai to pichle directory nama ko hata dena hai  

class Solution {
public:
    string simplifyPath(string path) {
        stack<string>ans;
        //hamne yaha ek stack bana diya string ka aur ham is stack mai valid strings ko push krte rahege.
        for(int i=0;i<path.length();i++)
        {
            //jo bhi '/' aayege unko ham ignore krte rahege. isse ham // vale cases ko  sove kr rhe hai
          if(path[i]=='/')
          continue;
          string temp;
          //next is loop ka break point ham '/' ko rakh rahe hai aur temp string mai saare characters ko store kr rahe hai 
          while(path[i]!='/' && i<path.length())
          {
            temp.push_back(path[i]);
            i++;
          }
          //now agar meri temp string mai '..' aata hai to mai pichle pushed string ko ans string mai se hata de raha hun.
          if(temp==".."&&(!ans.empty()))
            ans.pop();
            // else if se basiccaly ham '.' vale cases  ko ignore kr rahe hai
            //note kare ki ise especially deal isliye krna pada kyunki '..' vale cases ko ignore nhi kr skte hai. to agar suruvat mai '.' dekhte hi continue laga dete to '..' vale cases bhi ignore ho jate aur apne pichle directory name ko fir pop out nhi kr pate.
          else if(temp!=".."&&temp!=".")
          ans.push(temp);
        }
        string final;
        
      stack<string>ans2;
      // ab stack ke elements ko ham reverse kr rahe hai kyunki purane stack mai se strings pop out krte vakt arrangement ulti ho ja rhi hai unki
      while(!ans.empty())
      {
        ans2.push(ans.top());
        ans.pop();
      }
        final.push_back('/');
        // final string mai ham starting '/' ko dalkar kr rhe aur fir har ek string ke baad ek '/' daal rahe hai
        while(!ans2.empty())
        {
          final+=(ans2.top());
        final.push_back('/');
          ans2.pop();
        }
        // isse ham us case ko solve kr rahe ki agar last mai '/' hai to usse hata dena hai except of the case ki length 1 ya 1 se kam ho final ki        
       if(final.length()>1)
        final.pop_back();
        return final;
    }
}; 