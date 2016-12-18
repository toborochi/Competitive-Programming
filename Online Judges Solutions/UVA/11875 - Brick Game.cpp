#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
vector<int> v;
int main()
{
    IOS
    freopen("out.txt","w",stdout);
    int cases,n,val;
    cin>>cases;
    for(int c=1;c<=cases;++c)
    {
        cin>>n;
        v.assign(n,int());
        for(int i=0;i<n;++i)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        cout<<"Case "<<c<<": "<<v[n/2]<<endl;
    }
}
