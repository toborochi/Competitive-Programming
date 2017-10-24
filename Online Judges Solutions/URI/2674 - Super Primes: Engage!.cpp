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
const int maxn = (1e6)+50;
const int mod = (1e9)+7;
const int lim = (1e5);

const char filename_in[] = "in.txt";
const char filename_ou[] = "ou.txt";

bool sieve[maxn];

void sieveGen()
{
    memset(sieve,1,sizeof sieve);
    sieve[0]=0;
    sieve[1]=0;
    for (int i=2;i<=100050;++i)
    {
        if(sieve[i])
        {
            for(int j=i;j<=100050/i;++j)
            {
                sieve[i*j]=false;
            }
        }
    }

}

int check(int n)
{
    int aux = n;
    bool c = true;
    while(n>0)
    {
        if(!sieve[n%10])c=false;
        n/=10;
    }
    if(sieve[aux] && c) return 2;
    if(sieve[aux]) return 1;
    if(!sieve[aux])return 0;
}

int main()
{
    IOS
    cin.tie(0);
    ///freopen(filename_in,"r",stdin);
    ///freopen(filename_ou,"w",stdout);
    sieveGen();
    int n;
    while(cin>>n)
    {
        switch(check(n))
        {
            case 2 : cout<<"Super"<<endl; break;
            case 1 : cout<<"Primo"<<endl; break;
            case 0 : cout<<"Nada"<<endl; break;
        }
    }
}
/// This code is less virgin than me
