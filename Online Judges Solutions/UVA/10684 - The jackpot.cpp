#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
int arr[10000];

int kadane(int n)
{
    int a=arr[0],b=arr[0];
    for(int i=1;i<n;++i)
    {
        a=max(a+arr[i],arr[i]);
        b=max(a,b);
    }
    return b;
}

int main()
{
    IOS
    ///freopen("out.txt","w",stdout);
    int n;
    while(cin>>n)
    {
        if(!n)break;
        for(int i=0;i<n;++i)
        {
            cin>>arr[i];
        }
        int maxs=kadane(n);
        if(maxs>0)
        cout<<"The maximum winning streak is "<<maxs<<"."<<endl; else cout<<"Losing streak."<<endl;
    }
}
/// This code is less virgin than me
