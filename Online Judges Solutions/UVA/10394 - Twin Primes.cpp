#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

#define IOS ios::sync_with_stdio(0);
using namespace std;

vector<pair<int,int> > ans;
bool sieve[18409900];
void sieveGen()
{
    memset(sieve,true,sizeof sieve);
   long long i=2,j;
   sieve[0]=0;
   sieve[1]=0;
   while(i<=18409900)
   {
       if(sieve[i])
       {
        if(sieve[i-2]){ans.push_back(make_pair(i-2,i));}
        j=i;
        while(j<=18409900/i)
        {
            sieve[i*j]=false;
            ++j;
        }
       }
       ++i;
   }
}

int main()
{
    IOS
    cin.tie(NULL);
    sieveGen();
    long long n;
    while(cin>>n)
    {
        cout<<"("<<ans[n-1].first<<", "<<ans[n-1].second<<")"<<endl;
    }
}
/// Ghost Dancers Slay Together
