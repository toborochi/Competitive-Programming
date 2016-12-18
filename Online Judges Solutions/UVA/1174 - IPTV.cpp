#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

map<string,string> v;

string findSet(string x)
{
    if(v[x]==x)return x;
    return v[x]=findSet(v[x]);
}
bool isSameSet(string i,string j)
{
    return findSet(i)==findSet(j);
}
void unionSet(string i,string j)
{
    v[findSet(i)] = findSet(j);
}

int main()
{
    IOS
    int nods,edges,w,cases;
    string a,b;
    cin>>cases;
    int p=cases;
    vector<pair<int,pair<string,string> > > k;
    while(cases--){
    cin.ignore();
    cin>>nods>>edges;
    for(int i=0;i<edges;++i)
    {
        cin>>a>>b>>w;
        v[a]=a;
        v[b]=b;
        k.push_back(make_pair(w,make_pair(a,b)));
    }

    int mst=0;
    sort(k.begin(),k.end());
    for(int i=0;i<k.size();++i)
    {
        if(!isSameSet(k[i].second.first,k[i].second.second))
        {
            unionSet(k[i].second.first,k[i].second.second);
            mst+=k[i].first;
        }
    }
    cout<<mst<<endl;
    if(cases>0 && cases<p)cout<<endl;
    v.clear();
    k.clear();
}

    return 0;
}
