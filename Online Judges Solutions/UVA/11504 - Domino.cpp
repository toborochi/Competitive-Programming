#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define printl(name,n) for(int i=0;i<n;++i){cout<<name[i]<<" ";}cout<<endl;
using namespace std;

vector<vector<int> > graph;
vector<vector<int> > graph_reverse;
bool visited[100005];
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
void dfs_reverse(int p)
{
    visited[p]=1;
    for(int i=0;i<graph[p].size();++i)
    {
        if(!visited[graph[p][i]])
            dfs_reverse(graph[p][i]);
    }
}

int main()
{
    IOS
    int cases,nodes,edges,a,b;
    cin>>cases;
    while(cases--)
    {
        cin>>nodes>>edges;
        memset(visited,0,sizeof visited);
        graph.assign(nodes+1,vector<int>());
        graph_reverse.assign(nodes+1,vector<int>());
        for(int i=0;i<edges;++i)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph_reverse[b].push_back(a);
        }

        for(int i=1;i<=nodes;++i)
        {
            if(!visited[i])
                dfs(i);
        }
        memset(visited,0,sizeof visited);
        int answer=0;
        while(!topo.empty())
        {
            if(!visited[topo.top()])
            {
                ++answer;
                dfs_reverse(topo.top());
            }
            topo.pop();
        }
        cout<<answer<<endl;
    }
}
