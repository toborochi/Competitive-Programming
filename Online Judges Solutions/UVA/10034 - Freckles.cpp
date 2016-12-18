#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define par(a,b) make_pair(a,b)
#define printv(name) for(int i=0;i<name.size();++i){cout<<name[i].first<<"-"<<name[i].second<<endl;}
#define eulerdist(x2,y2,x1,y1) sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) )
using namespace std;

vector<pair<int,int> > points;
vector<pair<double,pair<int,int> > > k;
int v[105];

void initSet(int n)
{
    for(int i=0;i<=n;++i)v[i]=i;
}

int findSet(int x)
{
    if(v[x]==x) return x;
    return v[x] = findSet(v[x]);
}

void unionSet(int i,int j)
{
    v[findSet(i)]=findSet(j);
}

void maketree()
{
    double x2,y2,x1,y1;
    for(int i=0;i<points.size();++i)
    {
        x2 = points[i].first;
        y2 = points[i].second;
        for(int j=i+1;j<points.size();++j)
        {
            x1 = points[j].first;
            y1 = points[j].second;
            k.push_back(par(eulerdist(x2,y2,x1,y1),par(i,j)));
        }
    }
}

int main()
{
  ///freopen("data.txt","w",stdout);
  IOS
  bool aux=false;
  double x,y;
  int cases,n;
  cin>>cases;
  while(cases--)
  {
      cin>>n;
      initSet(n);
      points.assign(n,pair<int,int>());
      for(int i=0;i<n;++i)
      {
          cin>>x>>y;
          points[i]=par(x,y);
      }
      maketree();
      double ans=0;
      sort(k.begin(),k.end());

      for(int i=0;i<k.size();++i)
      {
          if(findSet(k[i].second.first)!=findSet(k[i].second.second))
          {
              unionSet(k[i].second.first,k[i].second.second);
              ///cout<<k[i].first<<endl;
              ans+=k[i].first;
          }
      }

      cout<<fixed<<setprecision(2)<<ans<<endl;
      if(cases > 0){cout<<endl;}

      points.clear();
      k.clear();
      ///printv(points);
  }
}

