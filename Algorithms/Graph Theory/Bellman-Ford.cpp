#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define PAR(a,b) make_pair(a,b)
#define printarray(n,name) for(int i=0;i<n;++i){cout<<name[i]<<" ";}
using namespace std;

const int MAXN = 100000;
const int inf = (1 << 30);
 bool cycle=0;

vector<pair<int,pair<int,int> > > graph;
int dist[MAXN],nodes,edges,a,b,w,u,v,root;

void bellman_ford()
{
    for(int i=0;i<nodes;++i)dist[i]=inf;

    dist[root]=0;

    for(int i=0;i<nodes-1;++i)
    {
        for(int j=0;j<edges;++j)
        {
            u=graph[j].second.first;
            v=graph[j].second.second;
            w=graph[j].first;
            ///cout<<u<<" "<<v<<" "<<w<<endl;
            if(dist[u]!=inf && dist[u]+w < dist[v])
            {
                dist[v] = dist[u]+w;
            }
        }
    }
    for(int j=0;j<edges;++j)
    {
         u=graph[j].second.first;
         v=graph[j].second.second;
         w=graph[j].first;
        if(dist[u]!=inf && dist[v] > dist[u] + w)
        {
            cycle=1;
            break;
        }
    }

}

int main()
{
    IOS
    ///freopen("out.txt","w",stdout);
    int cases;
    cin>>cases;
    while(cases--)
    {
        ///cout<<"Hello"<<endl;
        cin>>nodes>>edges;
        int timetoroot=0;
        for(int i=0;i<edges;++i)
        {
            cin>>a>>b>>w;
            if(a==nodes-1&&b==0){timetoroot=w;}
            graph.push_back(PAR(w,PAR(a,b)));
        }

        root=0;
        cycle=0;
        bellman_ford();

        cout<<cycle<<endl; ///SI HAY CICLOS NEGATIVOS
        printarray(nodes,dist) ///VECTOR DE DISTANCIAS

        ///cout<<dist[nodes-1]-timetoroot<<endl;
        graph.clear();
    }
}
/// This code is less virgin than me
