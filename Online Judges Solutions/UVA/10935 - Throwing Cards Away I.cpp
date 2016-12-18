#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
queue<int> wrk;
int main()
{
    IOS
    freopen("out.txt","w",stdout);
    int n;
    while(cin>>n)
    {
        if(!n)break;
        for(int i=1;i<=n;++i)wrk.push(i);

        cout<<"Discarded cards:";
        while(wrk.size()>1)
        {
            cout<<" "<<wrk.front();
            if(wrk.size()>2)cout<<",";
            wrk.pop();
            int tmp=wrk.front();
            wrk.pop();
            wrk.push(tmp);
        }cout<<endl;
        cout<<"Remaining card: "<<wrk.front()<<endl;
        wrk.pop();
    }
}
/// This code is less virgin than me
