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
const int maxn = 1e6;
const int mod = (1e9)+7;
const int lim = (1e5);

vector<long long> prime;
bool sieve[maxn+5];

void sievegen()
{
    memset(sieve,1,sizeof sieve);
    sieve[0]=sieve[1]=0;
    for(int i=2;i<=maxn;++i)
    {
        if(sieve[i])
        {
            prime.pb(i);
            for(int j=2;j<=maxn/i;++j)
            {
                sieve[i*j]=0;
            }
        }
    }

}

int main()
{
    IOS
    cin.tie(0);
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    sievegen();
    long long n;
    while(cin>>n)
    {
        if(!n)break;
        int ans=0;
        for(int i=0;i<prime.size();++i)
        {
            int tmp=0;
            for(int j=i;j<prime.size();++j)
            {
                tmp+=prime[j];
                if(tmp==n)++ans;
                if(tmp>n)break;
            }
            if(prime[i]>n)break;
        }
        cout<<ans<<endl;
    }
}
/// This code is less virgin than me
