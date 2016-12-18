#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

bool sieve[1000000];
void sieveGen()
{
   memset(sieve,true,sizeof sieve);
   long long i=2,j;
   sieve[0]=0;
   sieve[1]=0;
   while(i<=1000000)
   {
       if(sieve[i])
       {
        j=i;
        while(j<=1000000/i)
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
    ///freopen("out.txt","w",stdout);
    sieveGen();
    long long n,f=0;
    while(cin>>n&&n!=0)
    {
        f=0;
        for(int i=2;i<=n/2;++i)
        {
            if((n%i==0)&&(sieve[i]==1)){++f;}
        }
        if(sieve[n]==0) cout<<n<<" : "<<f<<endl; else cout<<n<<" : "<<1<<endl;

    }
}
