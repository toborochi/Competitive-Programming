#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

map<char,set<char> > graph;
map<char,bool> visited;
int comp,indv;

void dfs(char p)
{
    visited[p]=1;
    set<char>::iterator it;
    for(it = graph[p].begin();it != graph[p].end();++it)
    {
        if(!visited[*it])
        {
            dfs(*it);
        }
    }
}

void makelist()
{
    string lista;
    cin>>lista;
    for(int i=0;i<lista.size();i+=2)
    {
        visited[lista[i]]=0;
    }
}

int main()
{
    IOS
    cin.tie(0); cout.tie(0);
    string par;
    int cases;
    cin>>cases;
    while(cases--)
    {
        comp=indv=0;
        while(cin>>par)
        {
            if(par[0]=='*')break;

            graph[ par[1] ].insert(par[3]);
            graph[ par[3] ].insert(par[1]);
        }
        makelist();

        map<char,bool>::iterator it;
        for(it = visited.begin();it != visited.end();++it)
        {
            if((it->second)==0)
            {
                if(!graph.count(it->first))
                {
                    ++indv;
                }else
                {
                ++comp;
                dfs(it->first);
                }
            }
        }


        cout<<"There are "<<comp<<" tree(s) and "<<indv<<" acorn(s)."<<endl;
        graph.clear();
        visited.clear();
    }
}

/// Ghost Dancers Slay Together
