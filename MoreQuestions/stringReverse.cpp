#include<bits/stdc++.h>
using namespace std;

void reverse(string &str,int s,int e)
{//string ko reverse krna hai original vale ko hi isliye reference variable use kiya
    
    if(s>=e)
    return;
    
    else
    swap(str[s],str[e]);// swap pehle hi library mai defined hai isliye likhna nhi pada
    reverse(str,s+1,e-1);
    // first aur last character ko reverse kr diya fir front pointer ko increment krke next character pr gye aur rear pointer se previous pr gye aur again same function ko call kr rhe 

}
int main()
{
    string str;
    cin>>str;
    int s=0,e=str.length()-1;
    reverse(str,s,e);
    cout<<str;
}