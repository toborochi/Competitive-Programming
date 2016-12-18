#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define par(a,b) make_pair(a,b)
using namespace std;

int main()
{
    IOS
    int n,v[13];
    bool aux=false;
    while(true)
    {
        cin>>n;
        if(n==0)break;
        if(aux)cout<<endl;

        for(int i=0;i<n;++i)cin>>v[i];

        for(int a=0;a<n-5;++a){
            for(int b=a+1;b<n-4;++b)
                for(int c=b+1;c<n-3;++c)
                   for(int d=c+1;d<n-2;++d)
                       for(int e=d+1;e<n-1;++e)
                           for(int f=e+1;f<n;++f)
                               cout<<v[a]<<" "<<v[b]<<" "<<v[c]<<" "<<v[d]<<" "<<v[e]<<" "<<v[f]<<endl;}

        aux=true;

    }
}
