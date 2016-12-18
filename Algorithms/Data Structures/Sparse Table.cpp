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
const int INF = 1<<30;
const int maxn = 1e5;
const int spmax = log2(maxn) + 1;

int v[maxn],sparse[maxn][spmax];
bool visited;

void make_sparse(int n)
{
    for(int i=0;i<n;++i)
    {
        sparse[i][0]=i;
    }
    for(int j=1;(1<<j)<=n;++j)
    {
        for(int i=0;i+(1<<j)-1<n;++i)
        {
            if(v[sparse[i][j-1]]<v[sparse[i+(1<<(j-1))][j-1]])
            {
                sparse[i][j]=sparse[i][j-1];
            }else
            {
                sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
            }

        }
    }
}

int query(int a,int b)
{
    int l = b-a+1;
    int k = log2(l);
    return min(v[sparse[a][k]],v[sparse[a+l-(1<<k)][k]]);
}

int main()
{
    IOS
    cin.tie(0);
    ///freopen("out.txt","w",stdout);
    ///freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    ifor(0,n-1,v);
    make_sparse(n);
    /*
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<sparse[i][j]<<" ";
        }cout<<endl;
    }
    */
    
    int a,b;
    for(int i=0;i<10;++i)
    {
        cin>>a>>b;
        cout<<query(a,b)<<endl;
    }
}
/// This code is less virgin than me
