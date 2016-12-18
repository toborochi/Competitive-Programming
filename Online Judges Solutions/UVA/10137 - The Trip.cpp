#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#define IOS ios::sync_with_stdio(0);
using namespace std;

double v[1000];

double just2(double n)
{
    int temp = n*100.00;
    ///cout<<temp<<endl;
    double ans = temp/100.00;
    return ans;
}

int main()
{
    IOS
    ///freopen("out.txt","w",stdout);
    double n;
    while(cin>>n)
    {
        if(!n)break;
        double average=0,ans1,ans2;

        ans1=ans2=0.0;

        for(int i=0;i<n;++i){cin>>v[i];average+=v[i];}
        average/=n;
        ///cout<<average<<endl;
        for(int i=0;i<n;++i)
        {
            if(v[i]>average){ans1+=just2(v[i]- average);} else {ans2+= just2(average - v[i]);}
        }
        ///cout<<ans1<<endl;
        ///cout<<ans2<<endl;
        cout<<fixed<<setprecision(2);
        if(ans2<ans1) cout<<"$"<<ans1<<endl; else cout<<"$"<<ans2<<endl;
    }
}
/// Ghost Dancers Slay Together
