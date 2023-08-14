// Design and Implement an algorithm to Find Minimum Cost Spanning Tree of a given undirected 
// graph using Kruskal’s algorithm
/*
Algorithm
1)Sort all the edges in non-decreasing order of their weight. 
2)Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If the cycle is not formed, include this edge. Else, discard it. 
3) Repeat step 2 until there are (V-1) edges in the spanning tree.
o(eloge)
*/
#include<bits/stdc++.h>
using namespace std;

void makeset(vector<int>&parent,vector<int>&rank,int n)
{
    for(int i=0;i<n;i++)
   { parent[i]=i;
    rank[i]=0;}
}

int findparent(vector<int>&parent,int node)
{
    if(parent[node]==node)
    {
        return node;
    }
    return parent[node]= findparent(parent,parent[node]);
}

void unionset(int u ,int v,vector<int>&parent,vector<int>&rank)
{
    u= findparent(parent,u);
    v= findparent(parent,v);
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[u]>rank[v])
    {
        parent[v]=u;
    }
    else
    {
        parent[v]=u;
        rank[u]++;
    }
}

int kruskal(vector<pair<int,pair<int,int>>>&vec, int n)
{
    vector<int>parent(n);
    vector<int>rank(n);
    vector<vector<int>>ans;
    makeset(parent,rank,n);
    int minw=0;
    for(int i=0;i<vec.size();i++)
    {
        int u= findparent(parent, vec[i].second.first);
        int v= findparent(parent, vec[i].second.second);
        int w= vec[i].first;
        //cout<<u<<" -> "<<v;
        if(u!=v)
        {
            minw+= w;
            unionset(u,v,parent,rank);
            ans.push_back({vec[i].second.first,vec[i].second.second,w});
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<"move from "<<ans[i][0]<<" to "<<ans[i][1]<<" with weight "<< ans[i][2]<<endl;
    }

    return minw;
}



int main()
{
    int v,e;
    cin>>v>>e;
    
    vector<pair<int,pair<int,int>>>vec;
    for(int i=0;i<e;i++)
    {
        int a,b,w;
       // cout<<"enter the connected nodes and weight of their edges\n";
        cin>>a>>b>>w;
        vec.push_back(make_pair(w,make_pair(a,b)));
    }
    sort(vec.begin(),vec.end());
    cout<<"the Min spanning cost = "<<kruskal(vec,v);

}