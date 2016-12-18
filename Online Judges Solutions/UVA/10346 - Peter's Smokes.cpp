#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int main()
{
   IOS
   int n,k;
   while(cin>>n>>k)
   {
       cout<<n+(n-1)/(k-1)<<endl;
   }
}
