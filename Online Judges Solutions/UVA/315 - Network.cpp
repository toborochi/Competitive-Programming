#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#define IOS ios::sync_with_stdio(0);
using namespace std;

const int MAXN = 100005;

vector<vector<int> > graph;

bool visited[MAXN],ap[MAXN];
int indexo[MAXN],lowlink[MAXN];
int t=0,scc=0,root;

void dfs(int p)
{
    indexo[p]=lowlink[p]= ++t;
    visited[p]=1;
    for(int i=0; i<graph[p].size(); ++i)
    {
        int w=graph[p][i];
        if(visited[w]==0)
        {
            dfs(w);
            if(lowlink[w] >= indexo[p])
            {
                ap[p]=1;
            }
            lowlink[p] = min(lowlink[p],lowlink[w]);
        }
        else if(visited[w])
        {
            lowlink[p] = min(lowlink[p],indexo[w]);
        }
    }

}

int main()
{
    IOS
    freopen("out.txt","w",stdout);
    int nodes,mother;
    while(cin>>nodes)
    {
        if(!nodes) break;
        graph.assign(nodes+1,vector<int>());
        memset(visited,0,sizeof visited);
        memset(ap,0,sizeof ap);
        memset(indexo,0,sizeof indexo);
        memset(lowlink,0,sizeof lowlink);
        string conj;
        int son;
        cin.ignore();
        while(getline(cin,conj))
        {
            stringstream temp(conj);
            temp>>son;
            mother=son;
            if(!son)break;
/// NOTA: Recordar entrada para stringstream
            while(temp>>son)
            {
///cout<<son+1<<endl;
                graph[mother].push_back(son);
                graph[son].push_back(mother);
            }
        }
        for(root=1; root<=nodes; ++root)
        {
            dfs(root);
            if(ap[root]&&graph[root].size()<=1)ap[root]=0;
        }
        int ans=0;
        for(int i=1; i<=nodes; ++i)
        {
            ans+=ap[i];
        }
        cout<<ans-1<<endl;
    }

}
/// This code is less virgin than me
