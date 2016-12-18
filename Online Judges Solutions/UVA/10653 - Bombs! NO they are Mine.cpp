#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define bidirectional(a,b) graph[a].push_back(b);graph[b].push_back(a);
using namespace std;

int dist[1000001];
vector<vector<int> > graph;
int tab[1000][1000];
void bfs(int p)
{
    queue<int> q;
    q.push(p);
    dist[p]=0;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<graph[p].size();++i)
        {
            if(dist[graph[p][i]] != -1)
				continue;
			dist[graph[p][i]] = dist[p] + 1;
			q.push(graph[p][i]);
        }
    }
}
void initab(int y,int x)
{
    int node=1;
    for(int i=0;i<y;++i)
    {
       for(int j=0;j<x;++j)
        {
            tab[i][j]=node;
            ++node;
        }
    }
}
void uniontab(int x,int y)
{
    for(int i=0;i<y;++i)
    {
       for(int j=0;j<x;++j)
        {
            if(j<x-1 && tab[i][j+1]!=-1 && tab[i][j]!=-1){graph[tab[i][j]].push_back(tab[i][j+1]);}
            if(i<y-1 && tab[i+1][j]!=-1 && tab[i][j]!=-1){graph[tab[i][j]].push_back(tab[i+1][j]);}
            if(i>0 && tab[i-1][j]!=-1 && tab[i][j]!=-1){graph[tab[i][j]].push_back(tab[i-1][j]);}
            if(j>0 && tab[i][j-1]!=-1 && tab[i][j]!=-1){graph[tab[i][j]].push_back(tab[i][j-1]);}
        }
    }
}
int main()
{
   IOS
   int x,y,n,val,g,k;
   while(cin>>y>>x,x!=0||y!=0)
   {
        initab(y,x);
        cin>>n;
        while(n--)
        {
            cin>>val>>g;
            while(g--)
            {
                cin>>k;
                tab[val][k]=-1;
            }
        }
        graph.assign((x*y)+1,vector<int>());
        uniontab(x,y);
        /*for(int i=0;i<graph.size();++i)
        {
            cout<<i<<": ";
                 for(int j=0;j<graph[i].size();++j)
                {
                    cout<<graph[i][j]<<" ";
                }cout<<endl;
        }*/
        memset(dist,-1,sizeof dist);
        int fromx,fromy,tox,toy;
        cin>>fromy>>fromx>>toy>>tox;

        bfs(tab[fromy][fromx]);
        cout<<dist[tab[toy][tox]]<<'\n';
   }
}
