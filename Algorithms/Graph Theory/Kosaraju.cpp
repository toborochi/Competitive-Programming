//This algorithm works for Strongly Connected Components
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define printstk(stk) while(!stk.empty()){cout<<stk.top()<<endl;stk.pop();}
#define printv(v,n) for(int i=1;i<=n;++i){cout<<v[i]<<" ";}cout<<endl;
using namespace std;

const int MAXN=100005;
vector<vector<int> > graph;
vector<vector<int> > graph_reverse;
stack<int>k;
bool visited[MAXN];
int numCC=0;

void dfs(int p)
{
    visited[p]=true;
    for(int i=0;i<graph[p].size();++i)
    {
        if(!visited[graph[p][i]])
            dfs(graph[p][i]);
    }
    k.push(p);
}

void dfs_reverse(int p)
{
    visited[p]=true;
    for(int i=0;i<graph_reverse[p].size();++i)
    {
        if(!visited[graph_reverse[p][i]])
            dfs_reverse(graph_reverse[p][i]);
    }
}

int main()
{
    IOS
    int nods,edges,a,b;
    cin>>nods>>edges;
    graph.assign(nods+1,vector<int>());
    graph_reverse.assign(nods+1,vector<int>());
    memset(visited,false,sizeof visited);

    for(int i=0;i<edges;++i)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph_reverse[b].push_back(a);
    }

    for(int i=1;i<=nods;++i)
    {
        if(!visited[i])dfs(i);
    }
    ///printstk(k);
    ///printv(visited,nods);
    memset(visited,false,sizeof visited);
    while(!k.empty())
    {
        if(!visited[k.top()])
        {
            dfs_reverse(k.top());
            ++numCC;
        }
        k.pop();
    }
    cout<<numCC<<endl;

    return 0;
}
