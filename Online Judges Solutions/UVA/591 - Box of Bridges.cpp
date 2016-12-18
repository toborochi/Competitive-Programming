#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
int main()
{
    IOS
    int n,t=0,pro=0,val[105],s=1;
    while(cin>>n)
    {
        if(n==0)break;

        t=pro=0;

        for(int i=0;i<n;++i)
        {
            cin>>val[i];
            t+=val[i];
        }
        int answer=0;
        pro=t/n;
        for(int i=0;i<n;++i)
        {
            if(val[i]>pro){answer+=val[i]-pro;}
        }
        cout<<"Set #"<<s<<endl;
        cout<<"The minimum number of moves is "<<answer<<"."<<endl;
        ++s;
    }
}

/// Ghost Dancers Slay Together
