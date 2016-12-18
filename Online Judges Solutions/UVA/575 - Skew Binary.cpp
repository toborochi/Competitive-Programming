#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

const long long mod = (1e10)+7;

long long exp(long long a,long long b,long long c){
    if(b==0)return 1;
    unsigned long long dev=exp(a,b>>1,c);
    dev=(dev*dev)%c;
    if(b&1)dev=(dev*a)%c;
    return dev;
}

int main()
{
    IOS
    freopen("out.txt","w",stdout);
    string n;
    while(cin>>n)
    {
        if(n=="0")break;
        int answer=0,p=n.size();
        for(int i=0;i<n.size();++i)
        {
            answer+= (n[i]-48)*(exp(2,p,mod)-1);
            p--;
        }
        cout<<answer<<endl;
    }

}
