#include <bits/stdc++.h>
#define IOS                 ios::sync_with_stdio(0);
#define ll                  long long
#define ull                 unsigned long long
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
const int lim = (1e5);

const char filename_in[] = "in.txt";
const char filename_ou[] = "ou.txt";

int main()
{
    IOS
    cin.tie(0);
    ///freopen(filename_in,"r",stdin);
    ///freopen(filename_ou,"w",stdout);
    int n;
    string a,b;
    cin>>n;
    cin.ignore();
    while(n--)
    {
        string s;

        getline(cin,a);
        getline(cin,b);
        int i=0,j=0,c=0;
        while(i<a.size() && j<b.size())
        {
            if(c%2==0)
            {
                if(i<a.size())
                {
                    cout<<a[i];
                    cout<<a[i+1];
                    i+=2;
                }
            }else
            {
                if(j<b.size())
                {
                    cout<<b[j];
                    cout<<b[j+1];
                    j+=2;
                }
            }
            c++;
        }
        if(b.size()%2==0)
        {
            cout<<b[b.size()-2];
            cout<<b[b.size()-1];
        }else
        {
           cout<<b[b.size()-1];
        }

        cout<<endl;
    }
}
/// This code is less virgin than me
