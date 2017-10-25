#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
vector<vector<int> > graph;
vector<vector<int> > graph_reverse;
bool visited[2005];
stack<int> topo;
 
void dfs(int p)
{
    visited[p]=1;
    for(int i=0;i<graph[p].size();++i)
    {
        if(!visited[graph[p][i]])
            dfs(graph[p][i]);
    }
    topo.push(p);
}
 
void dfs2(int p)
{
    visited[p]=1;
    for(int i=0;i<graph_reverse[p].size();++i)
    {
        if(!visited[graph_reverse[p][i]])
            dfs2(graph_reverse[p][i]);
    }
}
 
int main()
{
    IOS
    long long nodes,edges,a,b;
    while(cin>>nodes>>edges)
    {
        long long scc=0;
        if(nodes==0 or edges==0)break;
        graph.assign(nodes+1,vector<int>());
        graph_reverse.assign(nodes+1,vector<int>());
        memset(visited,0,sizeof visited);
        for(long long i=0;i<edges;++i)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph_reverse[b].push_back(a);
        }
        for(long long i=1;i<=nodes;++i)
        {
            if(!visited[i])
                dfs(i);
        }
        memset(visited,0,sizeof visited);
        while(!topo.empty())
        {
            if(!visited[topo.top()])
            {
                ++scc;
                dfs2(topo.top());
            }
            topo.pop();
        }
        cout<<((scc==1)?"SI":"NO")<<endl;
    }
}
/// Blah, Blah & Porn
 
/**************************************************************
    Problem: 1014
    User: Vlada
    Language: C++
    Result: Accepted
    Time:56 ms
    Memory:1884 kb
****************************************************************/
