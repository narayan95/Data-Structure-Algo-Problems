//we basically used recursion and backtracking here and we are first finding a suitable path and then another suitable path and so oon with below #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9+7
void display(int *arr,int n)
{
for(int i=0;i<n;i++)
   cout<<arr[i]<<" " ;
   cout<<endl;
}
void getarray(int *arr,int n)
{
for(int i=0;i<n;i++)
   cin>>arr[i] ;
}
void solution()
{
int n;
cin>>n;
int arr[n];
getarray(arr,n);
}
int main()
{
  int t;
cin>>t;
while(t--)
{
  solution();
}
}

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    bool issafe(int x,int y,int n,vector<vector<int>> &m)
    {
       
        if(x>=0&&x<n&&y>=0&&y<n&&m[x][y]==1)
        return true;
        else
        return false;
    }
    
    void solve(vector<vector<int>> &m, int n,int x,int y,string path,vector<string>&ans)
    {
        if(x==n-1&&y==n-1)
        {
            ans.push_back(path);
            return ;
        }
      
            m[x][y]=0;
// we dont want that rat again come back to same block in single path thats why making it 0)
        //up( x means row and y means column)
        int newx= x-1,newy=y;
        if(issafe(newx,newy,n,m))
        {
            path.push_back('U');
            solve(m,n,newx,newy,path,ans);
            path.pop_back();
        }
        //down
         newx= x+1;
         newy=y;
        if(issafe(newx,newy,n,m))
        {
            path.push_back('D');
            solve(m,n,newx,newy,path,ans);
            path.pop_back();
        }
        //left
         newx= x;
         newy=y-1;
        if(issafe(newx,newy,n,m))
        {
            path.push_back('L');
            solve(m,n,newx,newy,path,ans);
            path.pop_back();
        }
        //RIGHT
         newx= x;
        newy=y+1;
        if(issafe(newx,newy,n,m))
        {
            path.push_back('R');
            solve(m,n,newx,newy,path,ans);
            path.pop_back();
        }
            m[x][y]=1;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int x=0,y=0;
        if(m[x][y]==0)
        return {"-1"};
        string path="";
        vector<string>ans;
        solve(m,n,x,y,path,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends