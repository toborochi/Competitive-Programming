#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

vector<pair<int,int> > ans;
int f(int n)
{
    int total=0;
    for(int i=2;i<sqrt(n);++i)
    {
        if(n%i==0){total+=i + n/i;}
    }
    if(total+1==n) return 0;
    if(total+1<n) return 1;
    if(total+1>n) return 2;
}
void printspaces(int n)
{
    for(int i=0;i<n;++i)cout<<" ";
}

int digits(int n)
{
    int t=0;
    while(n!=0)
    {
        ++t;
        n/=10;
    }
    return t;
}

int main()
{
    freopen("out.txt","w",stdout);
    IOS
    int n,m=0;
    while(cin>>n,n)
    {
        if(digits(n)>m)m=digits(n);
        if(n!=1) ans.push_back(make_pair(n,f(n))); else ans.push_back(make_pair(n,1));
    }

    cout<<"PERFECTION OUTPUT"<<endl;
    for(int i=0;i<ans.size();++i)
    {
        printspaces(m-digits(ans[i].first));
        cout<<ans[i].first<<" ";
        if(ans[i].second==0) cout<<" PERFECT"<<endl; else
        if(ans[i].second==1) cout<<" DEFICIENT"<<endl; else
        if(ans[i].second==2) cout<<" ABUNDANT"<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;
}
