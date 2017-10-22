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

string tip;

string lowc(string s)
{
    for(int i=0;i<s.size()-1;++i)
    {
        s[i]=tolower(s[i]);
    }
    return s;
}

bool checkType(string s)
{
    int n = 0;
    for(int i=1;i<s.size()-1;++i)
    {
        if(s[i]>='0' && s[i]<='9')n++;
    }
    if(s[0]=='-' || (s[0]>='0' && s[0]<='9'))n++;

    if(n==s.size()-1)return 0; else return 1;
}

int main()
{
    IOS
    string s;
    while(getline(cin,s))
    {
        vector<pair<string,string> > stringos;
        priority_queue<int> numbers;
        tip="";
        if(s==".")break;
        stringstream aux;
        string p;
        aux<<s;
        while(aux>>p)
        {
            p[p.size()-1]=' ';
            if(checkType(p)==0)
            {
                int val;
                stringstream n;
                n<<p;
                n>>val;
                numbers.push(val*-1);
                tip+="n";
            }else
            {
                stringos.pb({lowc(p),p});
                tip+="p";
            }
        }
        int j=0;
        sort(stringos.begin(),stringos.end());
        for(int i=0;i<tip.size();++i)
        {
            if(tip[i]=='n')
            {
                cout<<numbers.top()*-1; numbers.pop();
                if(i==tip.size()-1)cout<<".";
            }else
            {
                if(i==tip.size()-1)stringos[j].second[stringos[j].second.size()-1]='.';
                cout<<stringos[j].second;

                j++;
            }
            if(i<tip.size()-1)cout<<",";
            if(i<tip.size()-1)cout<<" ";
        }cout<<endl;
    }
}

/// This code is less virgin than me
