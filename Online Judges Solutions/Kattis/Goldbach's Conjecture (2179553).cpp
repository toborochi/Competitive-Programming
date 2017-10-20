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
const int maxn = (1e5)+50;
const int mod = (1e9)+7;
const int lim = (1e5);

const char filename_in[] = "in.txt";
const char filename_ou[] = "ou.txt";

const int tam = 32000+50;

set<pair<int,int> > st;
bool sieve[tam];

void solve(int x)
{
    for(int i=2;i<=x;++i)
    {
        if(sieve[i] && sieve[x-i])
        {
            st.insert( {min(i,x-i) ,max(i,x-i)} );
        }
    }
    cout<<x<<" has "<<st.size()<<" representation(s)"<<fl;
    set<pair<int,int> >::iterator it;

    for(it=st.begin();it!=st.end();it++)
    {
        cout<< (*it).first <<"+"<<(*it).second<<fl;
    }

    st.clear();
}

void sieveGen()
{
    memset(sieve,1,sizeof sieve);
    sieve[1]=0;
    for (int i=2;i<=tam;++i)
    {
        if(sieve[i])
        {
            for(int j=i;j<=tam/i;++j)
            {
                sieve[i*j]=false;
            }
        }
    }

}

int main()
{
    IOS
    cin.tie(0);
    ///freopen(filename_in,"r",stdin);
    ///freopen(filename_ou,"w",stdout);
    int n,m;
    cin>>n;
    sieveGen();
    while(n--)
    {
        cin>>m;
        solve(m);
        cout<<fl;
    }
}
/// This code is less virgin than me
