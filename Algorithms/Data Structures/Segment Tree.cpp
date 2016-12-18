#include <bits/stdc++.h>
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
const long long INF = 1<<30;
const int maxn = 1e5;


ll v[1000005];
ll tree[(sizeof v)*4];

void init(int node, int a, int b)
{
    if(a==b)
    {
        tree[node] = v[a];
        return;
    }
    init(2*node+1,a,(a+b)>>1);
    init(2*node+2,((a+b)>>1)+1,b);

    tree[node]= tree[2*node+1] + tree[2*node+2];
}
ll query(int node,int a,int b,ll p,ll q)
{
    if(q<a || b<p)return 0;
    if(p<=a&&b<=q)return tree[node];
    return query(2*node+1,a,(a+b)>>1,p,q) + query(2*node+2,((a+b)>>1)+1,b,p,q);
}

void update(int node,int a,int b,ll p,ll v)
{
    if(p<a || b<p)return;
    if(a==b)
    {
        tree[node] = v;
        return;
    }
    update(2*node+1,a,(a+b)>>1,p,v);
    update(2*node+2,((a+b)>>1)+1,b,p,v);
    tree[node] =  tree[2*node+1] + tree[2*node+2];
}

int main()
{
    IOS
    int n;
    cin>>n;
    for(int i=0;i<n;++i)cin>>v[i];
    init(0,0,n-1);

    cout<< query(0,0,n-1,0,n-1)<<endl;
    update(0,0,n-1,0,5);
    cout<< query(0,0,n-1,0,n-1)<<endl;

    return 0;
}

/// This code is less virgin than me
