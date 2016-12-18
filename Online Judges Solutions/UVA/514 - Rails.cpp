#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;
int main()
{
    IOS
    cin.tie(NULL); cout.tie(NULL);
    int n,x;
    while(cin>>n)
    {
        if(n==0)break;
        while(cin>>x)
        {
            if(x==0)break;
            stack<int>in;
            queue<int>out;
            for(int i=1;i<=n;i++)
            {
                if(i>1) {cin>>x;}
                out.push(x);
                in.push(i);

                while(!in.empty() && !out.empty() && in.top()==out.front())
                {
                    in.pop();
                    out.pop();
                }
            }
            if(in.empty()) cout<<"Yes"<<endl; else cout<<"No"<<endl;;
        }
        cout <<endl;
    }
}
/// Ghost Dancers Slay Together
