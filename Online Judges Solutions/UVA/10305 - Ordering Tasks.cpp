#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define unidirectional(a,b) graph[a].push_back(b);;
#define printstack(name,n) int i=0; while(!name.empty()){cout<<name.top(); if(i<n-1){cout<<" ";} ++i; name.pop();} cout<<endl;
using namespace std;

vector<vector<int> > graph;
bool visited[1000005];
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

int main()
{
   IOS
   int nodes,edges,a,b;
   while(cin>>nodes>>edges,nodes||edges)
   {
        graph.assign(nodes+1,vector<int>());
        memset(visited,0,sizeof visited);
        for(int i=0;i<edges;++i)
        {
            cin>>a>>b;
            unidirectional(a,b);
        }
        for(int i=1;i<=nodes;++i)
        {
            if(!visited[i])
                dfs(i);
        }
        printstack(topo,nodes);
   }
}
