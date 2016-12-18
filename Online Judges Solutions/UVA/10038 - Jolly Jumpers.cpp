#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int v[3000];
bool tmp[3000];

int main()
{
    IOS
    int n,val;
    while(cin>>n)
    {
        if(n==1){cin>>val; cout<<"Jolly"<<endl;} else
        {
            for(int i=0;i<n;++i)cin>>v[i];
            bool k=1;
            memset(tmp,0,sizeof tmp);
            for(int i=1;i<n;++i)
            {
                if(abs(v[i-1]-v[i]>=n)){k=0;}else{tmp[abs(v[i-1]-v[i])]=1;}
            }
            if(k==0){cout<<"Not jolly"<<endl;}
            else
            {
                k=1;
                for(int i=1;i<n;++i)
                {
                    ///cout<<tmp[i]<<endl;
                    if(tmp[i]==0)k=0;
                }
                if(k==0)cout<<"Not jolly"<<endl; else cout<<"Jolly"<<endl;
            }
        }
    }
}
