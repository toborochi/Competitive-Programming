#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
int main()
{
    IOS
    double n;
    while(cin>>n)
    {
        if(n==0)break;
        if(sqrt(n)- (int)(sqrt(n))==0) cout<<"yes"<<endl; else cout<<"no"<<endl;
    }
}
