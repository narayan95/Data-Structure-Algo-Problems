// Design and Implement Prim’s algorithm using Greedy Technique to display the minimum cost 
// achieved considering the scenario given.
// A car driver is given a set of locations to be covered with their distances by a company. Now the 
// company gives a privilege for the car driver to start at any arbitrary location. The constraint is entire 
// driving route chosen by the driver should be minimum.

/*Algorithm
1) Determine an arbitary vertex as the starting vertex of the MST
2) Follow steps 3 to 5 till there are vertices that are not included in the MST(known as fringe vertex)
3) Find edges connecting any tree vertex with the fringe vertex
4) Find the minimum among these edges
5) Add the chosen edge to the MST if it does not form a cycle 
6) Return the MST and exit
*/

#include<bits/stdc++.h>
#define infinity INT_MAX
using namespace std;

int prims(int **arr,int n)
{
    vector<int>key(n);
    vector<int>parent(n);
    vector<bool>mst(n);
    for(int i=0;i<n;i++)
    {
        key[i]= infinity;
        parent[i]=-1;
        mst[i]=0;
    }

    int s;
    cout<<"enter source vertex\n";
    cin>>s;
    // lets start the algo
    key[s]=0;
    for(int i=0;i<n;i++)
    {
        int mini=INT_MAX;
        int u;
        for(int v=0;v<n;v++)
        {
            if(mst[v]==false&& key[v]<mini)
            {
                u=v;
                mini=key[v];
            }
        }
        //mark min node as true
        mst[u]=true;
        //check its adjacent nodes
        for(int i=0;i<n;i++)
        {
            if(arr[u][i]&& arr[u][i]<key[i])
            {
                parent[i]=u;
                key[i]=arr[u][i];
            }
        }


    }
    for(int i=0;i<n;i++)
    {
        if(parent[i]!=-1)
        cout<<"move from "<< parent[i]<<" to "<< i <<" at the cost of "<<key[i] <<endl;
    }

        int cost=0;
        for(int i=0;i<n;i++)
        cost+=key[i];
        return cost;


}

int main()
{
    int v,e;
    cin>>v>>e;
    int **arr;
    arr= new int *[v];
    for(int i=0;i<v;i++)
    {
        arr[i]= new int [v];
    }
    cout<<"Enter the adjacency matrix"<<endl;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cin>>arr[i][j];
        }
    }
    int total_cost= prims(arr,v);
    cout<<"Total cost of spanning tree = "<<total_cost;


}