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


int main()
{
    IOS
    cin.tie(0);
    ///freopen(filename_in,"r",stdin);
    ///freopen(filename_ou,"w",stdout);
    int a,b;
    map<int,int> alice,bety;
    while(cin>>a>>b)
    {
        int v;
        if(!a&&!b)break;
        for(int i=0;i<a;++i)
        {
           cin>>v;
           alice[v]++;
        }
        for(int i=0;i<b;++i)
        {
            cin>>v;
            bety[v]++;
        }
        int x=0,y=0;
        map<int,int>::iterator it;
        for(it=alice.begin();it!=alice.end();++it)
        {
            if(!bety.count(it->first))
            {
                x++;
            }
        }
        map<int,int>::iterator ot;
        for(ot=bety.begin();ot!=bety.end();++ot)
        {
            if(!alice.count(ot->first))
            {
                y++;
            }
        }


        cout<<min(x,y)<<'\n';
        alice.clear();
        bety.clear();
    }
}
/// This code is less virgin than me
