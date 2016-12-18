#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
vector<int> v;
int main()
{
   IOS
   int n,mid;
   while(cin>>n)
   {
        v.push_back(n);
        sort(v.begin(),v.end());
        if(v.size()%2==0)
        {
            cout<<(v[v.size()/2]+v[v.size()/2-1])/2<<endl;
        }else{cout<<v[v.size()/2]<<endl;}
   }
}
