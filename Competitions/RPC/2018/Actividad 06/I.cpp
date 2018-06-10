#include <bits/stdc++.h>
#define IOS                 ios::sync_with_stdio(0);
#define ll                  long long
#define pb                  push_back
#define par(a,b)            make_pair(a,b)
#define fst                 first
#define scd                 second
#define pfor(a,b,name)      for(int i=a;i<=b;++i){cout<<name[i]<<" ";}cout<<'\n'
#define ifor(a,b,name)      for(int i=a;i<=b;++i){cin>>name[i];}
#define euclid(x1,y1,x2,y2) sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define lcm(a,b)            (a*b)/(__gcd(a,b))
#define gcd(a,b)            __gcd(a,b)
#define UMU                 cout<<"umu"<<endl
#define fl                  '\n'

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
    int cases,base,q;
    cin>>cases;
    while(cases--)
    {
        char c;
        cin>>base;
        map<char,int> d;
        for(int i=1;i<=base;++i)
        {
            cin>>c;
            d[c]=i;
        }
        string numb;

        cin>>q;
        while(q--)
        {
            long long total = 0;
            long long potencia = 1;
            cin>>numb;
            for(int i=numb.size()-1;i>=0;i--)
            {
                total += potencia*d[numb[i]];
                potencia*=base;
            }
            cout<<total<<'\n';
        }

    }
}
/// This code is less virgin than me
