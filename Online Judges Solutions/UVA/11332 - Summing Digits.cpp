#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

long long ans;
void f(long long n)
{
    if(n<10) {ans=n; return;}
    else
    {

    long long tmp=0;
    while(n!=0)
    {
        tmp+=n%10;
        n/=10;
    }
    f(tmp);
    }
}

int main()
{
    IOS
    long long n;
    while(cin>>n)
    {
        if(!n)break;
        f(n);
        cout<<ans<<endl;

    }
}
/// This code is less virgin than me
