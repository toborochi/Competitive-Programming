#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(false);
    int n,number;
    vector<int> v;
    cin>>n;
    while(n--)
    {
        cin>>number;
        v.push_back(number);
    }
    sort(v.begin(),v.end());
    int MAX=v[v.size()-1];
    int ig=0;
    while(ig!=v.size())
    {
        ig=0;
        for(int i=0;i<v.size();++i)
        {
            if(v[i]!=MAX){v[i]=v[i]*2;}
        }
        for(int p=0;p<v.size();++p)
        {
            if(v[p]==MAX){ig++;}
        }
    }
    cout<<ig-1<<endl;
 
 
    return 0;
}
 
/**************************************************************
    Problem: 1171
    User: Vlada
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1568 kb
****************************************************************/
