#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
vector<vector<int> > graph;
bool visited[105];

void readGraph()
{
    int node, next;
    while(cin>>node)
    {
        if(node==0)break;
        while(cin>>next)
        {
            if(next==0)break;
            graph[node].push_back(next);
        }
    }
}

void dfs(int p)
{
    for(int i=0;i<graph[p].size();++i)
    {
        if(!visited[graph[p][i]])
        {
            visited[graph[p][i]]=1;
            dfs(graph[p][i]);
        }
    }
}

void print(int totalnodes)
{
    int notReach = 0;
    vector<int> out;
    for(int x=1; x<=totalnodes;x++)
        if(visited[x]==0)
        {
            notReach++;
            out.push_back(x);
        }
    if(notReach == 0)
       cout<<0<<endl;
    else
        cout<<notReach<<" ";
    for(int x=0; x<out.size(); x++)
    {
        if(x==out.size() - 1)
           cout<<out[x]<<endl;
        else
            cout<<out[x]<<" ";
    }
}

int main()
{
    IOS
    int nodes, queries,node;
    while(cin>>nodes,nodes)
    {

    graph.assign(nodes+1, vector<int>());
    readGraph();
    cin>>queries;
    for(int i=0;i<queries;i++)
    {
        memset(visited,0,sizeof visited);
        cin>>node;
        dfs(node);
        print(nodes);
    }
    }
 }
