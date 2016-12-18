#include <iostream>
#include <vector>
#include <algorithm>
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
const int maxn = 1e4+1;

int k[maxn*2],numsets=0;

void init(int n)
{
    for(int i=1;i<=n;++i)
    {
        k[i]=i;
    }
    numsets=n;
}

int findSet(int x)
{
    if(k[x]==x) return x;
    return k[x] = findSet(k[x]);
}

bool isSame(int i,int j)
{
    return findSet(i) == findSet(j);
}

void unionSet(int i,int j)
{
    if(!isSame(i,j)) numsets--;
    k[findSet(i)] = findSet(j);
}


int main()
{
    IOS
    cin.tie(0);
    ///freopen("out.txt","w",stdout);
    ///freopen("in.txt","r",stdin);
    long long cases,nodes,edges,cost,u,v,c,p=1;
    cin>>cases;
    while(cases--)
    {
        vector<pair<long long,pair<int,int> > > graph;
        cin>>nodes>>edges>>cost;
        for(int i=0;i<edges;++i)
        {
            cin>>u>>v>>c;
            graph.pb({c,{u,v}});
        }
        sort(graph.begin(),graph.end());
        init(nodes);
        long long mst=0,l=0;
        for(int i=0;i<edges;++i)
        {
            u = graph[i].second.first;
            v = graph[i].second.second;
            c = graph[i].first;
            if(c>=cost || l>nodes-1)break;
            if(!isSame(u,v))
            {
                unionSet(u,v);
                mst+=c;
                ++l;
            }
        }
        int air = 0;
        for(int i=1;i<=nodes;++i)
        {
            if(k[i]==i)
            {
                mst+=cost;
                air++;
            }
        }
        cout<<mst<<air<<endl;
        ++p;
    }
}
/// This code is less virgin than me
