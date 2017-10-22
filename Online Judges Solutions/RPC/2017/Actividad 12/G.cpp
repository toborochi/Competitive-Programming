#include <bits/stdc++.h>
#define IOS                 ios::sync_with_stdio(0);
#define ll                  long long
#define pb                  push_back
#define par(a,b)            make_pair(a,b)
#define pfor(a,b,name)      for(int i=a;i<=b;++i){cout<<name[i]<<" ";}
#define ifor(a,b,name)      for(int i=a;i<=b;++i){cin>>name[i];}
#define euclid(x1,y1,x2,y2) sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define lcm(a,b)            (a*b)/(__gcd(a,b))
#define gcd(a,b)            __gcd(a,b)
#define UMU                 cout<<"umu"<<endl;
#define fl                  '\n'

using namespace std;

const double pi = 3.14159265;
const int INF = 1<<30;
const int maxn = (1e6)+300050;
const int mod = (1e9)+7;
const int lim = (1e5);
const int tam = maxn;

const char filename_in[] = "in.txt";
const char filename_ou[] = "ou.txt";

bool sieve[maxn];
vector<int> primes;

void sieveGen()
{
    memset(sieve,1,sizeof sieve);
       sieve[0]=0;
        sieve[1]=0;
    for (int i=2;i<=tam;++i)
    {
        if(sieve[i])
        {
            ///primes.pb(i);
            for(int j=i;j<=tam/i;++j)
            {
                sieve[i*j]=false;
            }
        }
    }

}

void solve(int a,int b)
{
    int gap;
    gap=0;
    vector<int> tmp;
    for(int i=a;i<=b;++i)
    {

        if(sieve[i]){tmp.pb(i);}
        if(tmp.size()==2)
        {
           int x,y;
           x=tmp[0];
           y=tmp[1];
           gap=max(gap,y-x);
           tmp.clear();
           tmp.pb(y);
        }
    }
    if(gap==0) cout<<"NULL"<<endl; else cout<<gap<<endl;
}

int main()
{
    IOS
    sieveGen();
    int a,b;
    while(cin>>a>>b)
    {
        if(!a&&!b)break;

        if(a>b)swap(a,b);

        solve(a,b);
    }
}
/// This code is less virgin than me
