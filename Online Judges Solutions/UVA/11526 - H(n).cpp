#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);

long long H(int n)
{
    long long res = 0;
    for( int i = 1; i <((int)sqrt(n)) + 1 ; i=i+1 )
    {
        res += n/i;
    }
    int aux = ((int)sqrt(n));
    return (res*2 - aux*aux);
}

using namespace std;
int main()
{
    IOS
    cin.tie(0); cout.tie(0);
    int cases,n;
    cin>>cases;
    while(cases--)
    {
        cin>>n;
        cout<<H(n)<<endl;
    }
}

/// Ghost Dancers Slay Together
