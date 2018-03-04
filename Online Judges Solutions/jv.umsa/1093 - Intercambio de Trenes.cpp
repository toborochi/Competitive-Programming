#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio();
using namespace std;
 
int main()
{
    IOS
    int cases,n;
    cin>>cases;
    while(cases--){
     cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
 
    int answer=0;
    for (int i = 1; i<v.size();++i)
    {
    int j=i;
    while (j > 0 && v[j-1] > v[j])
        {
        swap(v[j],v[j-1]);
        answer++;
        j--;
        }
    }
    cout<<answer<<endl;
 
    }
    return 0;
}
 
/**************************************************************
    Problem: 1093
    User: Vlada
    Language: C++
    Result: Accepted
    Time:12 ms
    Memory:1568 kb
****************************************************************/
