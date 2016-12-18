#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define externalfile freopen("out.txt","w",stdout);
using namespace std;

int main()
{
    IOS
    int x1, y1, x2, y2, temp_x, temp_y;
    while(cin>>x1>>y1>>x2>>y2, x1 != 0 && y1 != 0 && x2 != 0 && y2 != 0){

        if (x1 > x2) temp_x = x1 - x2;
        else temp_x = x2 - x1;

        if (y1 > y2) temp_y = y1 - y2;
        else temp_y = y2 - y1;

        if (x1 == x2 && y1 == y2) {cout<<0<<endl;}
        else if (x1 == x2 || y1 == y2 || temp_x == temp_y) cout<<1<<endl;
        else cout<<2<<endl;
    }

}
/// Ghost Dancers Slay Together
