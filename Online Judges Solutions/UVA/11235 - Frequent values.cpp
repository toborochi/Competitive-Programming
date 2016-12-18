#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

vector<pair<int,int> > v;
vector<pair<int,int> > tree;
map<int,int> tmp;
const int inf = 1<<30;

void maketree(int node, int a, int b)
{
	if(a == b)
	{
		tree[node] = v[a];
		return;
	}
	maketree(2*node+1,a,(a+b)>>1);
	maketree(2*node+2,((a+b)>>1)+1,b);

    if(tree[2*node+1].second<=tree[2*node+2].second)
    {
        tree[node] = tree[2*node+1];
    }else{tree[node] = tree[2*node+2];}
}

pair<int,int> query(int node, int a, int b, int p, int q)
{
    pair<int,int> misc;
    misc.first=inf;
    misc.second=inf;

	if(q < a || b < p)
		return misc;

	if(p <= a && b <= q)
		return tree[node];

	return min(query(2*node+1,a,(a+b)>>1,p,q),query(2*node+2,((a+b)>>1)+1,b,p,q));
}

int main()
{
    IOS
    int n,q,from,to,val;
    while(cin>>n)
    {
        if(n==0)break;
        cin>>q;
        v.assign(n+1,pair<int,int>());
        tree.assign(n*4,pair<int,int>());
        for(int i=0;i<n;++i){cin>>val;v[i].first=val; tmp[val]++; }
        for(int i=0;i<n;++i){v[i].second=tmp[v[i].first];}
        ///for(int i=0;i<n;++i){cout<<v[i].second<<" ";}cout<<endl;

        maketree(0,0,n-1);

        while(q--)
        {
            cin>>from>>to;
            from--;to--;
            pair<int,int> ans;
            ans=query(0,0,n-1,from,to);
            cout<<ans.first<<endl;
        }
    }
}
