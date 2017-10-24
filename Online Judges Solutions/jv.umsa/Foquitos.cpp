#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
 
const int MAXN = 1e5;
vector<vector<int> > graph;
bool visited[MAXN+1];
int degree[MAXN+1],rec;
 
void dfs(int p)
{
    visited[p]=1;
    ++rec;
    for(int i=0;i<graph[p].size();++i)
    {
        if(!visited[graph[p][i]])
        {
            dfs(graph[p][i]);
        }
    }
}
 
int main()
{
    IOS
    ///freopen("out.txt","w",stdout);
    int nodes,q,a,b,source,cases;
    cin>>cases;
    while(cases--)
    {
    cin>>nodes>>q;
    graph.assign(nodes+1,vector<int>());
    memset(visited,0,sizeof visited);
    memset(degree,0,sizeof degree);
    for(int i=0;i<nodes-1;++i)
    {
        cin>>a>>b;
        degree[a]++;
        graph[b].push_back(a);
    }
    for(int i=0;i<q;++i)
    {
        cin>>source;
        dfs(source);
    }
    int total=0;
    for(int i=1;i<=nodes;++i)
    {
        if(degree[i]==0&&!visited[i])
        {
            rec=0;
            dfs(i);
            total+=rec;
        }
    }
    cout<<nodes-total<<endl;
    }
}
/// This code is less virgin than me
 
/**************************************************************
    Problem: 1075
    User: Vlada
    Language: C++
    Result: Accepted
    Time:156 ms
    Memory:7572 kb
****************************************************************/
