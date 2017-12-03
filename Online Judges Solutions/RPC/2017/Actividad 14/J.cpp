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


vector<string> lista;

int main()
{
  int n;
  while(cin>>n)
  {
    lista.assign(n,string());
    for(int i=0;i<n;++i)
    {
        cin>>lista[i];
    }
    set<string> st;
    string lstr;
    for(int i=0;i<3;++i)
    {
      string tmp = lista[i];
      sort(tmp.begin(),tmp.end());
      if(st.find(tmp)!=st.end()){lstr = tmp;}
      st.insert(tmp);
    }

    int fila,columna;

    fila=columna=-1;

    for(int i=0; i<n; ++i)
    {
      for(int j=0; j<n; ++j)
      {
        char curr = lista[i][j];
        for(int k=0;k<j;++k)
        {
          if(fila==-1 && curr==lista[i][k])
          {
            fila = i;
            for(int p=0;p<n;++p)
            {
              if(p!=i && lista[p][j]==curr)columna=j;
            }
            if(columna == -1)columna=k;
          }
        }
        if(lstr.find(curr)==-1)
        {
           fila=i;
           columna=j;
        }
      }
    }

    int ansR,ansC;
    char ansT;
    for(int i=0;i<lstr.size();++i)
    {
      if(lista[fila].find(lstr[i]) == -1)
      {
          ansR = fila+1;
          ansC = columna+1;
          ansT = lstr[i];
      }
    }
     cout<<ansR<<" "<<ansC<<" "<<ansT<<endl;

  }
}
/// This code is less virgin than me
