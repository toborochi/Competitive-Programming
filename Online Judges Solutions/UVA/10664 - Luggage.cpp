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

using namespace std;

const int pi = 3.14159265;
const int INF = 1<<30;
const int maxn = 1e5;

bool T[205][205];
int  input[maxn];

bool subset(int n,int x)
{
    T[0][input[0]]=1;
    for(int i=0;i<n;++i){T[i][0]=1;} /// 0's
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<=x;++j)
        {
            if(j<input[i]){ T[i][j]=T[i-1][j]; }else
            {
                if(T[i-1][j] || T[i-1][j-input[i]])
                {
                    T[i][j]=1;
                }else
                {
                    T[i][j]=0;
                }
            }
        }
    }

    return T[n-1][x];
}


int main()
{
    IOS
    cin.tie(0);
    ///freopen("out.txt","w",stdout);
    ///freopen("in.txt","r",stdin);
    int cases;
    string s;
    cin>>cases;
    cin.ignore();
    while(cases--)
    {
        memset(T,0,sizeof T);
        int n,total=0,i=0;
        getline(cin,s);
        stringstream tmp;
        tmp<<s;
        while(tmp>>n)
        {
            total+=n;
            input[i]=n;
            ++i;
        }
        if(total%2!=0){cout<<"NO"<<'\n';}else
        {
            if(subset(i,total/2)){cout<<"YES"<<'\n';}else {cout<<"NO"<<'\n';}
        }
    }
}
/// This code is less virgin than me
