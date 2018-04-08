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
#define dbg()               cout<<"umu"<<endl;

using namespace std;

const double pi = 3.14159265;
const int INF = 1<<30;
const int maxn = (1e5)+50;
const int mod = (1e9)+7;
const int lim = (1e5);

const char filename_in[] = "in.txt";
const char filename_ou[] = "ou.txt";

int a[maxn/2],b[maxn/2],c[maxn],aux[maxn];

int main()
{
    IOS
    cin.tie(0);
    ///freopen(filename_in,"r",stdin);
    ///freopen(filename_ou,"w",stdout);
    int cases,n,val;
    cin>>cases;
    for(int i=1;i<=cases;++i)
    {
        int pos=-1;
        cin>>n;
        for(int j=0;j<n;++j)
        {
            cin>>val;
            c[j]=val;
            if(j%2==0)a[j/2]=val; else b[(j-1)/2]=val;
        }

        int y=n/2,x=(n+1)/2;

        sort(c,c+n);
        sort(a,a+x);
        sort(b,b+y);

        for(int k=0;k<x;++k)
        {
            aux[k*2]=a[k];
        }
        for(int k=0;k<y;++k)
        {
            aux[k*2 + 1]=b[k];
        }

        for(int j=0;j<n && pos==-1;++j)
        {
            if(c[j]!=aux[j])pos=j;
        }

        cout<<"Case #"<<i<<": ";

        if(pos==-1)cout<<"OK"; else cout<<pos;

        cout<<'\n';
    }
}
/// This code is less virgin than me
