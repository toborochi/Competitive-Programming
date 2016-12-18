#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int ans[10];

void makedigits(int n)
{
    while(n!=0)
    {
        ans[n%10]++;
        n/=10;
    }
}

void f(int n)
{
    for(int i=1;i<=n;++i)makedigits(i);
}
void printans()
{
    for(int i=0;i<10;++i)
    {
        cout<<ans[i];
        cout<< ((i<9)?" ":"");
    }cout<<endl;
}
int main()
{
   IOS
   freopen("out.txt","w",stdout);
   int n,cases;
   cin>>cases;
   while(cases--)
   {
       cin>>n;
       memset(ans,0,sizeof ans);
       f(n);
       printans();
   }
}
