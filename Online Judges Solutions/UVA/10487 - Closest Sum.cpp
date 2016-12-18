#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define par(a,b) make_pair(a,b)
using namespace std;

int v[1001];
int closest(int val,int n)
{
    int answer,dif=1<<30;
    for(int i=0;i<n;++i)
    {
        int tmp=v[i];
        for(int j=0;j<n;++j)
        {
            if(i!=j)
            {
                tmp+=v[j];

                if(abs(val-tmp)<= dif){dif=abs(val-tmp);answer=tmp;}
                tmp-=v[j];
            }
        }
    }
    return answer;
}

int main()
{
    IOS
    int n,q,val,c=1;
    while(cin>>n,n)
    {
        for(int i=0;i<n;++i)cin>>v[i];
        cout<<"Case "<<c<<":"<<endl;
        cin>>q;
        while(q--)
        {
            cin>>val;
            cout<<"Closest sum to "<<val<<" is "<<closest(val,n)<<"."<<endl;
        }
        ++c;
    }

}
