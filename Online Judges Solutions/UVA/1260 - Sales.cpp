#include <iostream>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int v[1001];

int main()
{
    IOS
    ///freopen("out.txt","w",stdout);
    int cases,n,ans;
    cin>>cases;
    while(cases--)
    {
        cin>>n;
        ans=0;
        for(int i=0;i<n;++i)
        {
            cin>>v[i];
            for(int j=0;j<i;++j)
            {
                if(v[j]<=v[i])++ans;
            }
        }
        cout<<ans<<endl;
    }
}
/// This code is less virgin than me
