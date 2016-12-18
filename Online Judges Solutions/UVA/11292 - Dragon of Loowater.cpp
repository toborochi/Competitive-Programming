#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define par(a,b) make_pair(a,b)
using namespace std;

int main()
{
    IOS
    int n,m;
    while(cin>>n>>m,n!=0&&m!=0)
    {
        vector<int> dragon(n),knigth(m);
        for(int i=0;i<n;++i){cin>>dragon[i];}
        for(int i=0;i<m;++i){cin>>knigth[i];}
        sort(dragon.begin(),dragon.end());
        sort(knigth.begin(),knigth.end());
        int gold=0,d=0,k=0;
        while(d<n && k<m)
        {
            while(dragon[d]>knigth[k] && k<m)++k;
            if(k==m) break;
            gold+=knigth[k];
            ++d;
            ++k;
        }
        if(d==n) cout<<gold<<endl; else cout<<"Loowater is doomed!"<<endl;

    }
}
