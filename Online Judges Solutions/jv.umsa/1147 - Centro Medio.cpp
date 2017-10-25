#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
 
int main()
{
    IOS
    double n;
    while(cin>>n)
    {
        double a = ((n*(n+1))/2);
        long long b = (sqrt(a));
        if(a==b*b)cout<<b<<endl;else cout<<"NO"<<endl;
    }
    return 0;
}
 
 
/**************************************************************
    Problem: 1147
    User: Vlada
    Language: C++
    Result: Accepted
    Time:52 ms
    Memory:1572 kb
****************************************************************/
