#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
int main()
{
    IOS
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        cout<<"The parity of ";
        int siz = 31 - __builtin_clz(n), bton = __builtin_popcount(n);
        while(siz>=0)
        {
            if(n&(1<<siz)) cout<<1; else cout<<0;
            siz--;
        }cout<<" is "<<bton<<" (mod 2)."<<endl;
    }
}
/// Ghost Dancers Slay Together
