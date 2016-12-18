#include <iostream>
#include <vector>
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

vector<string> land;

int dirx[] = {1,0,-1,0};
int diry[] = {0,1,0,-1};


void flood(int y,int x)
{
    land[y][x]='#';
    for(int i=0;i<4;++i)
    {
        int xx = dirx[i] + x;
        int yy = diry[i] + y;
        if(xx>=0 && xx<80 && yy>=0 && yy<30 && land[yy][xx]==' ')
        {
            flood(yy,xx);
        }
    }
}

void printland()
{
        for(int j=0;j<land.size();++j)
        {
            cout<<land[j]<<endl;
        }
}

int main()
{
    IOS
    cin.tie(0);
    ///freopen("out.txt","w",stdout);
    ///freopen("in.txt","r",stdin);
    int cases;
    string s,f="*";
    cin>>cases;
    int auxi = cases;
    while(cases>0)
    {
        int i=0,y=0,x=0;
        string sep;
         if(cases==auxi){cin.ignore();}
        getline(cin,s);
        ///cout<<s<<"*"<<endl;
        string top = s;
        while(getline(cin,s))
        {
            ///cout<<s<<"<-"<<endl;
            if(s[0]=='_'){sep=s; cases--; break;}
            ///cout<<s<<"<-"<<endl;
            int pos = s.find(f);
            if(pos>=0)
            {
                x=pos;
                y=i;
            }
            land.pb(s);
            ++i;
        }
        cout<<top<<endl;
        ///cout<<land[0].size()<<endl;
        flood(y,x);
        printland();
        cout<<sep<<endl;
        land.clear();
    }
}
/// This code is less virgin than me
