#include <iostream>
#include <map>
#include <vector>
#define ll unsigned long long
using namespace std;
 
map<ll,ll> mp;
 
ll facto(ll n)
{
    ll num=1;
    for(ll i=1;i<=n;++i)
    {
        num*=i%1000000007;
        num%=1000000007;
    }
    return num%1000000007;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(false);
    ll n,number;
    cin>>n;
    while(n--)
    {
         cin>>number;
         mp[number]++;
    }
    map<ll,ll>:: iterator it;
    ll total=1;
    vector<int> v;
    for(it=mp.begin();it!=mp.end();++it)
    {
        total*= facto(it->second);
        total=total%1000000007;
        ///cout<<facto(it->second)<<endl;
        ///v.push_back(facto(it->second));
    }
    /*
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<endl;
    }*/
    cout<<total<<endl;
    return 0;
}
 
/**************************************************************
    Problem: 1211
    User: Vlada
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1700 kb
****************************************************************/
