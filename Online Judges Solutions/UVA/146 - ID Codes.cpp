#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
int main()
{
    IOS
    string wrk;
    while(cin>>wrk,wrk!="#")
    {
        if(next_permutation(wrk.begin(),wrk.end())){cout<<wrk<<endl;}
        else {cout<<"No Successor"<<endl;}
    }
}
