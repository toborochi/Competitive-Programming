#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int main()
{
    IOS
    ///freopen("out.txt","w",stdout);
    int cases,a,b,m,n;
    cin>>cases;
    while(cases--)
    {
        cin>>a>>b;
        m = ( (a-b) * ((a-b<0)?-1:1) ) /2;
        n = a - m;
        if(m+n==a&&abs(m-n)==b){cout<<max(m,n)<<" "<<min(m,n)<<endl;} else cout<<"impossible"<<endl;

    }
}
