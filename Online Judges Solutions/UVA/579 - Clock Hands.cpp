#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
int main()
{
    IOS
    int hour,minute;
    char misc;
    while(cin>>hour>>misc>>minute)
    {
        if(hour==0&&minute==0)break;
        cout<<fixed<<setprecision(3);
        double angle=(abs((0.5*(60*hour-11*minute))));
        if(angle>180) cout<<360-angle<<endl; else cout<<angle<<endl;

    }
}
/// Ghost Dancers Slay Together
