#include <bits/stdc++.h>
#define IOS                 ios::sync_with_stdio(0);
#define ll                  long long
#define pb                  push_back
#define par(a,b)            make_pair(a,b)
#define pfor(a,b,name)      for(int i=a;i<=b;++i){cout<<-name[i]<<((i<b)?" ":""); }cout<<endl;
#define ifor(a,b,name)      for(int i=a;i<=b;++i){cin>>name[i];}
#define euclid(x1,y1,x2,y2) sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define lcm(a,b)            (a*b)/(__gcd(a,b))
#define gcd(a,b)            __gcd(a,b)
#define dbg                 cout<<"YAHALO"<<endl;
 
using namespace std;
 
const int pi = 3.14159265;
const int INF = 1<<30;
const int maxn = 1e5;
const int mod = (1e18)+7;
 
vector<int> v;
priority_queue<vector<int> > pq;
 
ll exp(ll a,ll b,ll c){
    if(b==0)return 1;
    ll dev=exp(a,b>>1,c);
    dev=(dev*dev)%c;
    if(b&1)dev=(dev*a)%c;
    return dev;
}
 
int main()
{
    IOS
    cin.tie(0);
    ///freopen("out.txt","w",stdout);
    ///freopen("in.txt","r",stdin);
    int n;
    while(cin>>n)
    {
        v.assign(n,int());
        ifor(0,n-1,v);
        for(int i=1;i<exp(2,n,mod);++i)
        {
            int bts = __builtin_popcount(i);
            vector<int> tmp;
            if(bts==6)
            {
                for(int j=0;j<49;++j)
                {
                    if(i&(1<<j)){tmp.pb(-v[j]);}
                }
                pq.push(tmp);
            }
        }
        vector<int> aux;
        while(!pq.empty())
        {
            aux = pq.top();
            pq.pop();
            pfor(0,5,aux);
        }
    }
}
/// This code is less virgin than me
 
/**************************************************************
    Problem: 1274
    User: Vlada
    Language: C++
    Result: Accepted
    Time:308 ms
    Memory:1716 kb
****************************************************************/
