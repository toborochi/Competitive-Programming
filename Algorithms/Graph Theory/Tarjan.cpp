#include <bits/stdc++.h>
#define IOS                 ios::sync_with_stdio(0);
#define ll                  long long
#define pb                  push_back
#define par(a,b)            make_pair(a,b)
#define pfor(a,b,name)      for(int i=a;i<=b;++i){cout<<name[i]<<" ";}cout<<'\n';
#define ifor(a,b,name)      for(int i=a;i<=b;++i){cin>>name[i];}
#define euclid(x1,y1,x2,y2) sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define lcm(a,b)            (a*b)/(__gcd(a,b))
#define gcd(a,b)            __gcd(a,b)

using namespace std;

const int pi = 3.14159265;
const int INF = 1<<30;
const int maxn = 1e5;

vector<vector<int> > graph;

int scc[maxn],tnum[maxn],tlow[maxn],t=0,nscc=0;
bool instack[maxn];
stack<int> s;

void tarjan(int u)
{
    tlow[u]=tnum[u]=t++;
    instack[u]=1;
    s.push(u);
    for(int i=0;i<graph[u].size();++i)
    {
        int v = graph[u][i];
        if(tnum[v]==-1)
        {
            tarjan(v);
        }
        if(instack[v])
        {
            tlow[u] = min(tlow[u],tlow[v]);
        }
    }
    if(tnum[u]==tlow[u])
    {
        int v;
        do
        {
            v = s.top();
            instack[v]=0;
            s.pop();
            scc[v]=nscc;
        }while(u!=v);
        nscc++;
    }
}

int main()
{
    IOS
    cin.tie(0);
    ///freopen("out.txt","w",stdout);
    ///freopen("in.txt","r",stdin);
    int nodes,edges,u,v;
    cin>>nodes>>edges;

    graph.assign(nodes+1,vector<int>());

    for(int i=0;i<edges;++i)
    {
        cin>>u>>v;
        graph[u].pb(v);
    }
    memset(tnum,-1,sizeof tnum);
    memset(tnum,-1,sizeof tnum);

    for(int i=1;i<=nodes;++i)
    {
        if(tnum[i]==-1)
        {
            tarjan(i);
        }
    }
    cout<<"N# of Strongly Connected Components: "<<nscc00<<endl;
    for(int i=1;i<=nodes;++i)
    {
        cout<<"Node # "<<i<<" belongs to the component # "<<scc[i]<<endl;
    }

}
/// This code is less virgin than me
/// Main code provided by Gauss - Bolivia
