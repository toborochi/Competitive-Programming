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
    int cases;
    cin>>cases;
    string s,checker;
    while(cases--)
    {
        cin>>s;
        checker="";
        for(int i=0;i<s.size();++i)
        {
            int j=i;
            while(s[j]==s[i])
            {

                j++;
            }
            checker+=s[i];
            i=j-1;
        }
        int total=checker.size() - ((checker[checker.size()-1]=='b')?1:0 );
        cout<<total<<endl;




    }
}
/// This code is less virgin than me
