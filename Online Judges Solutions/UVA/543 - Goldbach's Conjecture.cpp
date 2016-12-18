#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);

using namespace std;
bool sieve[1000000];
void sieveGen()
{
    memset(sieve,true,sizeof sieve);
   int i=2,j;
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
   sieveGen();
   int n,a,b;
   freopen("out.txt","w",stdout);
   while(cin>>n)
   {
       if(n==0)break;
       for(int i=2;i<n;++i)
       {
           if(sieve[i]&&sieve[n-i]){a=i;b=n-i;break;}
       }
       cout<<n<<" = "<<a<<" + "<<b<<endl;
   }
}
