#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int steps;
string val;
long long numbah;

bool pal(string a)
{
    string b=a;
    reverse(b.begin(),b.end());
    return ((a==b)? 1 : 0);
}

void makeanswer()
{
    while(!pal(val))
    {
        stringstream ss,ss2,tmp;
        ss<<val;
        reverse(val.begin(),val.end());
        ss2<<val;
        long long a,b;
        ss>>a;
        ss2>>b;
        numbah=a+b;
        tmp<<numbah;
        tmp>>val;
        ++steps;
    }
    ///cout<<numbah<<endl;
}

int main()
{
    IOS
    ///freopen("out.txt","w",stdout);
    int cases;
    cin>>cases;
    while(cases--)
    {
        cin>>val;
        steps=0;
        makeanswer();
        if(!pal(val))
        cout<<steps<<" "<<numbah<<endl;
        else
        cout<<steps<<" "<<val<<endl;
    }
}
/// This code is less virgin than me
