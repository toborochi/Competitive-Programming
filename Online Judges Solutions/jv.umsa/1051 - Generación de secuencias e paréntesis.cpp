#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
 
void parsis(int o,int c,string a)
{
    if (o==0 && c==0){cout<<a<<endl;}
 
    if (o > 0)parsis(o-1,c+1,a+"(");
    if (c > 0)parsis(o,c-1,a+")");
 
}
 
int main()
{
    IOS
    int n;
    while(cin>>n){
    parsis(n,0,"");
    }
    return 0;
}
 
/**************************************************************
    Problem: 1051
    User: Vlada
    Language: C++
    Result: Accepted
    Time:940 ms
    Memory:1560 kb
****************************************************************/
