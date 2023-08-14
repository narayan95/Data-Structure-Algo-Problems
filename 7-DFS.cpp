// Design and Implement an algorithm to check whether a given graph is connected or not using Depth 
// First Search (DFS). Use stack for constructing DFS spanning tree traversal and Display the DFS traversal order

/*
    Psuedo Code:
    DFS(G,v):
    q.push(v);
    visited[v]=true;
    while(q not empty)
    {
        do{
            curr= v.pop()
            for all adjacent vertex u of curr in G)
            do{
                if(visited[u]!= true )
                {
                    q.push(u)
                    visited[u]=true
                }
            }
    }

*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int **arr, int v)
{
     vector<bool>visited(v,0);
    int s;
    cout<<"enter the source vertex\n";
    cin>>s;
    stack<int>q;
    q.push(s);
    visited[s]=1;
    while(!q.empty())
    {
        int curr= q.top();
        q.pop();
        cout<<curr<<" ";
        for(int i=0;i<v;i++)
        {
            if(arr[curr][i]&& visited[i]==0)
            {
                visited[i]=1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int v;
    cout<<"enter the number of vertices\n";
    cin>>v; 
    int **a;
    a = new int* [v];
    for(int i=0;i<v;i++)
    a[i]= new int[v];
    cout<<"enter the adjacency matrix\n";
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"the adjacency matrix is\n";
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    dfs(a,v);

}
