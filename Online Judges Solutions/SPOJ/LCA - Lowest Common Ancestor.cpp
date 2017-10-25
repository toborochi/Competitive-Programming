#include <bits/stdc++.h>
#define IOS                 ios::sync_with_stdio(0);
#define ll                  long long
#define pb                  push_back
#define par(a,b)            make_pair(a,b)
#define pfor(a,b,name)      for(int i=a;i<=b;++i){cout<<name[i]<<" ";}cout<<endl;
#define ifor(a,b,name)      for(int i=a;i<=b;++i){cin>>name[i];}
#define euclid(x1,y1,x2,y2) sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define lcm(a,b)            (a*b)/(__gcd(a,b))
#define gcd(a,b)            __gcd(a,b)

using namespace std;

const int pi = 3.14159265;
const int INF = 1<<30;
const int maxn = 1e4;
const int spmax = log2(maxn) + 1;

int fst[maxn+1],sparse[maxn+1][spmax],t=0;
vector<vector<int> > graph;
vector<int> path,v;
bool visited[maxn+1];

void make_sparse(int n)
{
    for(int i=0;i<n;++i)
    {
        sparse[i][0]=i;
    }
    for(int j=1;(1<<j)<=n;++j)
    {
        for(int i=0;i+(1<<j)-1<n;++i)
        {
            if(v[sparse[i][j-1]]<v[sparse[i+(1<<(j-1))][j-1]])
            {
                sparse[i][j]=sparse[i][j-1];
            }else
            {
                sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
            }

        }
    }
}

int query(int a,int b)
{
    int l = b-a+1;
    int k = log2(l);
    if(v[sparse[a][k]]<v[sparse[a+l-(1<<k)][k]])
    {
        return path[v[sparse[a][k]]];
    }else
    {
        return path[v[sparse[a+l-(1<<k)][k]]];
    }

}

void dfs(int u)
{
    if(fst[u]==-1){fst[u]=t;}
    v.pb(fst[u]);

    visited[u]=1;
    path.pb(u);
    ++t;
    for(int i=0;i<graph[u].size();++i)
    {
        if(!visited[graph[u][i]])
        {
            dfs(graph[u][i]);
            path.pb(u);
            v.pb(fst[u]);
            ++t;
        }
    }
}

int main()
{
    IOS
    cin.tie(0);
    ///freopen("out.txt","w",stdout);
    ///freopen("in.txt","r",stdin);
    int cases;
    cin>>cases;
    for(int c=1;c<=cases;++c)
    {
        int nodes,n,q,a,b;
        cin>>nodes;

        graph.assign(nodes+1,vector<int>());
        for(int u=1;u<=nodes;++u)
        {
            cin>>n;
            for(int i=0;i<n;++i)
            {
                cin>>b;
                graph[u].pb(b);
                graph[b].pb(u);
            }
        }
        memset(visited,0,sizeof visited);
        memset(fst,-1,sizeof fst);
        dfs(1);

        make_sparse(v.size());

        /*
        pfor(0,path.size()-1,path); ///Camino del recorrido
        pfor(0,v.size()-1,v); ///Orden del Recorrido
        pfor(1,nodes,fst);            /// Primera aparicion
        */
        cout<<"Case "<<c<<":"<<'\n';
        cin>>q;
        while(q--)
        {
            cin>>a>>b;
            int lo = min(fst[a],fst[b]);
            int hi = max(fst[a],fst[b]);
            ///cout<<lo<<" "<<hi<<endl;
            cout<<query(lo,hi)<<'\n';
        }
        t=0;
        path.clear();
        v.clear();
    }
}
/// This code is less virgin than me
