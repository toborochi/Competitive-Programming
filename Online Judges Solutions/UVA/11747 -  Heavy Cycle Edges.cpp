#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int v[1005];
void init(int n)
{
    for(int i=0;i<n;++i)v[i]=i;
}
int findSet(int x)
{
    if(v[x]==x) return x;
    return v[x] = findSet(v[x]);
}
void unionSet(int i,int j)
{
    v[findSet(i)] = findSet(j);
}

int main()
{
    IOS
    int nods,edges,a,b,w;
    while(cin>>nods>>edges,nods)
    {
        vector<pair<int,pair<int,int> > > k;
        for(int i=0;i<edges;++i)
        {
            cin>>a>>b>>w;
            k.push_back(make_pair(w,make_pair(a,b)));
        }
        sort(k.begin(),k.end());
        vector<int> ans;
        init(nods);
        bool found = 0;
        int n_cycles=0;
        for(int i=0;i<edges;++i)
        {
            if(findSet(k[i].second.first)==findSet(k[i].second.second))
            {
                ans.push_back(k[i].first);
                found=1;++n_cycles;
            }
            else
            {
                unionSet(k[i].second.first,k[i].second.second);
            }

        }
        if(found==0)cout<<"forest"<<endl; else
        {
            for(int i=0;i<n_cycles;++i)
            {
                cout<<ans[i];
                if(i<n_cycles-1)cout<<" ";
            }cout<<endl;
        }
    }

    return 0;
}
