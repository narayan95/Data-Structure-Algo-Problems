// Design and Implement an algorithm to find the single source shortest path to other vertices using 
// Dijkstra’s algorithm from a given vertex in a weighted connected graph.
/* Algorithm:
    1)The idea is to generate a SPT (shortest path tree) with a given source as a root. Maintain an Adjacency Matrix with two sets, 
    -> one set contains vertices included in the shortest-path tree, 
    -> other set includes vertices not yet included in the shortest-path tree. 
    At every step of the algorithm, find a vertex that is in the other set (set not yet included) and has a minimum distance from the source.
    (e+v)logv
*/

#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>>&edges, int vertex, int edge , int source)
{
     unordered_map<int, list<pair<int,int>>>adj;
     for(int i=0;i<edge;i++)
     {
        int u= edges[i][0];
        int v= edges[i][1];
        int w= edges[i][2];
        adj[u].push_back({make_pair(v,w)});
        adj[v].push_back({make_pair(u,w)});
     }
     vector<int>dist(vertex,INT_MAX);
        set<pair<int,int>>st;
        dist[source]=0;
        st.insert(make_pair(0,source));
        while(!st.empty())
        {
            // fetch top node
            auto top= *(st.begin());
            int nodeDist= top.first;
            int topnode= top.second;


            // remove top node now
            st.erase(st.begin());

            // negihbours

        for( auto neighbour: adj[topnode])
        {
            if(nodeDist+ neighbour.second < dist[neighbour.first])
            {
                auto record= st.find(make_pair(dist[neighbour.first],neighbour.first));
                if(record!= st.end())
                {
                     st.erase(record);
                }
                dist[neighbour.first]=nodeDist+ neighbour.second ;
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }

        }
    for(int i=0;i<dist.size();i++)
    {
        cout<< dist[i]<<" ";
    }

}

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    vector<vector<int>>edges;
    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});

    }
    int s;
    cin>>s;
    dijkstra(edges,vertex,edge,s);

}