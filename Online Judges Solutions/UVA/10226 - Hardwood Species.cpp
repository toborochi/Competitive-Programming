#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define p(name) name->first
#define s(name) name->second
using namespace std;

map<string,double> tmp;

int main()
{
   IOS
   cin.tie(NULL);
   ///freopen("out.txt","w",stdout);
   double cases,total,aux;
   string ss;
   cin>>cases;
   aux=cases;
   cin.ignore();
   while(cases--)
   {
       total=0;
       getline(cin,ss);
       if(ss!=""){
       tmp[ss]++;
       total++;}
       while(getline(cin,ss)&&ss!="")
       {
          if(ss!=""){
          tmp[ss]++;
          ++total;}
       }
       map<string,double>:: iterator it;
       for(it=tmp.begin();it!=tmp.end();++it)
       {
            cout<<p(it)<<" ";
            cout<<fixed<<setprecision(4)<<(100/total)*s(it) <<endl;
       }
       if(cases>0)cout<<endl;
       tmp.clear();
   }
}
