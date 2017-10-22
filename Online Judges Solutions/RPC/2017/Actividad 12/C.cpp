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

void binCoefi(int n)
{
    if(n==0){cout<<1<<endl; return;}

    unsigned long long C[n+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, n); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }
    int p1=n,p2=0;
    for(int i=0;i<=n;++i)
    {

        if(C[i]>1)cout<<C[i];

        if(p1>0)
        {
            cout<<"x";
            if(p1>1)cout<<"^"<<p1;
        }
        if(p2>0)
        {
            cout<<"y";
            if(p2>1)cout<<"^"<<p2;
        }
        if(i<n)cout<<"+";
        p1--;
        p2++;

    }cout<<endl;
}

int main()
{
    IOS
    cin.tie(0);
    ///freopen(filename_in,"r",stdin);
    ///freopen(filename_ou,"w",stdout);
    int cases,a;
    cin>>cases;
    while(cases--)
    {
        cin>>a;
        binCoefi(a);
    }
}
/// This code is less virgin than me
