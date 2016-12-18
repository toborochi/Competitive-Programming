#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
using namespace std;

int pos[10000];
vector<string> answer;

int main()
{
    IOS
    freopen("out.txt","w",stdout);
    int cases;
    bool nw=1;
    cin>>cases;
    string line;
     cin.ignore();
    while(cases--)
    {
         cin.ignore();
        getline(cin,line);

        if(!nw)cout<<endl;
        nw=0;
        if(cases==0)nw=1;

        stringstream tmp;
        tmp<<line;
        int n,i=1;
        string val;
        while(tmp>>n){pos[i]=n;++i;}

        answer.assign(i,string());
        --i;

        for(int j=1;j<=i;++j)
        {
            cin>>val;
            answer[pos[j]]=val;
        }
        for(int j=1;j<=i;++j){cout<<answer[j]<<endl;}

        if(!nw)cin.ignore();
        nw=0;

        answer.clear();
        ///cout<<"YAHALLO (~ ^-^)~"<<endl;
    }
}
/// This code is less virgin than me
