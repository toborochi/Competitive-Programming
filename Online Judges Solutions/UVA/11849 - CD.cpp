#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

set<int> tmp;

int main()
{
    IOS
    int n,m,val;
    while(cin>>n>>m,n!=0&&m!=0)
    {
        int answer=0;
        while(n--)
        {
            cin>>val;
            tmp.insert(val);
        }
        while(m--)
        {
            cin>>val;
            if(tmp.count(val))++answer;
        }
        cout<<answer<<endl;
        tmp.clear();
    }

}
