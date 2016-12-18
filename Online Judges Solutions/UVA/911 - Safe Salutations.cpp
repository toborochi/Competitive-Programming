#include <iostream>
#define IOS ios::sync_with_stdio(0);
using namespace std;
int answers[]={1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012};
int main()
{
    IOS
    cin.tie(0);
    cout.tie(0);
    ///freopen("out.txt","w",stdout);
    int n;
    bool b=0;
    while(cin>>n)
    {
        if(b!=0)cout<<endl;
        cout<<answers[n]<<endl;
        b=1;
    }
}
/// This code is less virgin than me
