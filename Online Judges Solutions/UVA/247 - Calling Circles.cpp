#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define printstk(stk) while(!stk.empty()){cout<<stk.top()<<endl;stk.pop();}
#define printv(v,n) for(int i=1;i<=n;++i){cout<<v[i]<<" ";}cout<<endl;
using namespace std;

map<string,set<string> > graph;
map<string,set<string> > graph_reverse;
stack<string>k;
map<string,bool> visited;
vector<vector<string> > ansv;
int numCC=0;
bool blank=false;

void dfs(string p)
{
    visited[p]=true;
    set<string>::iterator it;
    for(it=graph[p].begin();it!=graph[p].end();++it)
    {
        if(!visited[*it])
            dfs(*it);
    }
    k.push(p);
}

void dfs_reverse(string p)
{
    visited[p]=true;
    ansv[numCC].push_back(p);
    set<string>::iterator it;
    for(it=graph_reverse[p].begin();it!=graph_reverse[p].end();++it)
    {
        if(!visited[*it])
            dfs_reverse(*it);
    }
}
int main()
{
    ///freopen("out.txt","w",stdout);
    IOS
    int nods,edges,caso=1;

    string a,b;
    nods=1;
    edges=1;
    bool firstin=true;
    while(cin>>nods>>edges)
    {
    if (nods==0&&edges==0) break;

    for(int i=0;i<edges;++i)
    {
        cin>>a>>b;
        visited[a]=0;
        visited[b]=0;
        graph[a].insert(b);
        graph_reverse[b].insert(a);
    }
    map<string,bool>::iterator ot;

    for(ot=visited.begin();ot!=visited.end();++ot)
    {
        if(!(ot->second))dfs(ot->first);
    }

    ///printstk(k);
    ///printv(visited,nods);
    map<string,bool>::iterator po;
    for(po=visited.begin();po!=visited.end();++po)
    {
        po->second=0;
    }
    numCC=0;
    ansv.assign(nods+1,vector<string>());
    while(!k.empty())
    {
        if(!visited[k.top()])
        {
            dfs_reverse(k.top());
            ++numCC;
        }
        k.pop();
    }
    /// RESPUESTA
    if(blank)cout<<endl;
    blank = true;
    cout<<"Calling circles for data set "<<caso<<":"<<endl;
    bool p;
    for(int i=0;i<ansv.size();++i)
    {
        p=false;
        if(ansv[i].size()>0){
        for(int j=0;j<ansv[i].size();++j)
        {
            if (p) cout<<", ";
            p= true;
            cout<<ansv[i][j];
        }
        cout<<endl;
        }
    }
    ///cout<<endl;
    visited.clear();
    graph.clear();
    graph_reverse.clear();
    ++caso;
    }

    return 0;
}
