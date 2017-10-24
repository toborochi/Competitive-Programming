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

map<char,char> indx,indx2;

void makemap(string a,string b)
{
    for(int i=0;i<a.size();++i)
    {
        indx[ tolower(b[i]) ] = a[i] ;
        indx2[ tolower(a[i]) ] = b[i] ;
    }
}

string convert(string s)
{
    for(int i=0;i<s.size();++i)
    {
        if(indx.count(tolower(s[i])))
        {
            if(s[i]>='A' && s[i]<='Z')s[i] = toupper( indx[tolower(s[i])] ); else
            if(s[i]>='a' && s[i]<='z')s[i] = tolower( indx[tolower(s[i])] ); else
            s[i] = tolower(indx[tolower(s[i])]);
        }else if(indx2.count(tolower(s[i])))
        {
            if(s[i]>='A' && s[i]<='Z')s[i] = toupper( indx2[tolower(s[i])] ); else
            if(s[i]>='a' && s[i]<='z')s[i] = tolower( indx2[tolower(s[i])] ); else
            s[i] = tolower(indx2[tolower(s[i])]);
        }
    }

    return s;
}

int main()
{
    IOS
    string a,b,sentence;
    int n,c;
    while(cin>>n>>c)
    {
        cin.ignore();
        getline(cin,a);
        getline(cin,b);
        makemap(a,b);

        while(c--)
        {
            getline(cin,sentence);
            cout<<convert(sentence)<<endl;
        }cout<<endl;
        indx.clear();
        indx2.clear();
    }
}
/// This code is less virgin than me
